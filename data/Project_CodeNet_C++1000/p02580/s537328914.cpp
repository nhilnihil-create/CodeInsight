#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
set<P> s;
vector<P> H(323456),W(323456);
template<typename T>
void fin(T a){
  cout<<a<<endl;
  exit(0);
}

signed main(){
  int h,w,m;cin>>h>>w>>m;
  for(int i=0;i<323456;i++)H[i]=W[i]=P(0,i);
  for(int i=0;i<m;i++){
    int hh,ww;cin>>hh>>ww;
    H[hh].first++;
    W[ww].first++;
    s.insert(P(hh,ww));
  }
  sort(H.rbegin(),H.rend());
  sort(W.rbegin(),W.rend());
  for(int i=0;H[i].first==H[0].first;i++)
    for(int j=0;W[j].first==W[0].first;j++)
      if(!s.count(P(H[i].second,W[j].second)))
        fin(H[0].first+W[0].first);
  fin(H[0].first+W[0].first-1);
}

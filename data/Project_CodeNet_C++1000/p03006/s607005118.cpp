#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin>>N;
  vector<int> p(N);
  vector<int> q(N);
  map<pair<int,int>,int> m;
  vector<pair<int,int>> c;
  for(int i=0;i<N;i++){
    cin>>p.at(i)>>q.at(i);
    for(int j=0;j<i;j++){
      int a=p.at(i)-p.at(j),b=q.at(i)-q.at(j);
      if(a<0){
        a*=-1,b*=-1;
      }
      if(a==0){
        b=abs(b);
      }
      c.push_back(make_pair(a,b));
      m[make_pair(a,b)]++;
    }
  }
  int Z=0;
  for(auto x:c){
    Z=max(Z,m[x]);
  }
  cout<<N-Z<<endl;
    
}
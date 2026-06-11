#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,m,q;
  cin>>n>>m>>q;
  vector<int> a(q);
  vector<int> b(q);
  vector<int> c(q);
  vector<int> d(q);
  for(int i=0;i<q;i++){
    cin>>a.at(i)>>b.at(i)>>c.at(i)>>d.at(i);
    a.at(i)--;
    b.at(i)--;
  }
  vector<bool> p;
  for(int i=0;i<n;i++)
    p.push_back(0);
  for(int i=0;i<m-1;i++)
    p.push_back(1);
  bool f=1;
  int ma=0;
  while(f){
    vector<int> x;
    int ai=1;
    for(int i=0;i<(int)p.size();i++){
      if(p.at(i))
        ai++;
      else
        x.push_back(ai);
    }
    int s=0;
    for(int i=0;i<q;i++)
      s+=(x.at(b.at(i))-x.at(a.at(i))==c.at(i)?d.at(i):0);
    ma=max(s,ma);
    f=next_permutation(p.begin(),p.end());
  }
  cout<<ma<<endl;
}
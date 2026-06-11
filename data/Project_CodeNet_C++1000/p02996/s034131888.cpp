#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main(){
  int n;cin>>n;
  vector<pair<int,int>> p(n);
  REP(i,n){
    int a,b;cin>>a>>b;
    p.at(i)=make_pair(b,a);
  }
  sort(p.begin(),p.end());

  ll time=0;bool f=true;
  REP(i,n){
    time+=p.at(i).second;
    if(time>p.at(i).first) f=false;
  }

  cout<<(f?"Yes":"No");
}
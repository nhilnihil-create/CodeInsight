#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n);i++)
using ll = long long;
const ll MOD=1000000007;



int main() 
{
  ll N; cin>>N;
  ll time=0;
  vector<pair<ll,ll>> list(N);
  rep(i,N)
  {
    cin>>list.at(i).second>>list.at(i).first;
  }
  sort(list.begin(),list.end());
  rep(i,N)
  {
    time+=list.at(i).second;
    if(time>list.at(i).first) {cout<<"No"<<endl; return 0;}
  }
  cout<<"Yes"<<endl;
  return 0;
}

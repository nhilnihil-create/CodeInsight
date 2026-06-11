#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll N;
int main(){
  cin>>N;
  ll n=1;
  for(ll i=0;i<N;i++)
    n*=2;
  set<ll>S;map<ll,ll>M;ll Min=1;S.insert(1);
  for(ll i=0;i<n;i++){
  ll a;cin>>a;a*=-1;if(a<Min)Min=a;
    S.insert(a);
    if(M.count(a))
      M.at(a)++;
    else
      M[a]=1;
  }bool judge=true;
  multiset<ll>S1;S1.insert(Min);M.at(Min)--;
  if(M.at(Min)==0)S.erase(Min);
  for(ll i=0;i<N;i++){
  multiset<ll>S2;
    for(auto x:S1){
    auto itr=S.upper_bound(x);
    ll a=*itr;if(a==1){judge=false;break;}
      S2.insert(a);M.at(a)--;
      if(M.at(a)==0)S.erase(a);
     }if(!judge)break;
     for(auto x:S2){
     S1.insert(x);
     }
  }if(judge)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
  return 0;
}
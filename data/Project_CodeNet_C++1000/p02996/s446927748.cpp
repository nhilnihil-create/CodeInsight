#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)




using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll Nmax=1e9;
const ll INF=1e9;



int main(){
  ll n;
  cin>>n;
  vector<pair<ll,ll>> ab(n);

  rep(i,n){
    cin>>ab[i].second>>ab[i].first;// 必要時間，締め切り
  }
  sort(ab.begin(),ab.end());//締め切り順に並べる

  ll time=0;

  rep(i,n){
    time+=ab[i].second;
    //cout<<time<<" "<<ab[i].first<<endl;
    if(time>ab[i].first){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;



}

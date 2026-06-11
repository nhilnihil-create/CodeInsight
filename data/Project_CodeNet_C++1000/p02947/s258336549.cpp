#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)




using namespace std;
using ll = long long;
using P = pair<int,int>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const ll Nmax=1e9;



int main(){
  ll n;
  cin>>n;
  vector<string> s(n);
  map<string,int> mp;
  ll ans=0;
  rep(i,n){
    cin>>s[i];
    sort(s[i].begin(),s[i].end());
    if(mp[s[i]]>0){
    	ans+= mp[s[i]];
    }
    mp[s[i]]+=1;
  }
  cout<<ans;


  return 0;





}

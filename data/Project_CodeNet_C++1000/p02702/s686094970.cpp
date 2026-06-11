#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define P pair<ll,ll>

int main(){
  string s;
  cin>>s;
  reverse(s.begin(),s.end());
  int n=s.size();
  int ans=0;
  vector<int> rs(n+1);
  rs[0]=0;
  int tmp=1;
  rep(i,n){
    rs[i+1]=(rs[i]+(int)(s[i]-'0')*tmp)%2019;
    tmp=tmp*10%2019;
  }
  map<int,int> mp;
  for(auto x : rs){
    mp[x]++;
  }
  for(auto x : mp){
    ans+=(x.second)*(x.second-1)/2;
  }
  cout<<ans<<endl;
}
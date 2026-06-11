#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,sum=0,tmp=0,diff=1e9;cin>>n;
  lvector W(n);rep(i,n) {cin>>W[i];sum+=W[i];}
  rep(i,n) {
    tmp+=W[i],sum-=W[i];
    diff=min(diff,abs(tmp-sum)); 
  }
  print(diff);
  return 0;
}
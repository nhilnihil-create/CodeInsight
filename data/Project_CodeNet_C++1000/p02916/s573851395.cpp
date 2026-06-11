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
  ll n,ans=0;cin>>n;
  lvector A(n),B(n),C(n-1);
  rep(i,n) cin>>A[i];rep(i,n) cin>>B[i];rep(i,n-1) cin>>C[i];
  rep(i,n) {
    ans+=B[A[i]-1];
    if(i+1<n&&A[i]+1==A[i+1]) ans+=C[A[i]-1];
  }
  print(ans);
  return 0;
}
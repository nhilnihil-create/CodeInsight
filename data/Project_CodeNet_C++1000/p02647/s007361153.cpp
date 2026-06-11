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
  ll n,k,pos;cin>>n>>k;
  lvector A(n);rep(i,n) cin>>A[i];
  ll lim=min(50ll,k);
  lvector B(n,0);
  rep(i,n) {
    pos=max(0ll,i-A[i]);
    B[pos]++;
    if(i+A[i]+1<n) B[i+A[i]+1]--;
  }
  rep(i,n-1) B[i+1]+=B[i];
  rep(i,lim-1) {
    lvector tmp(n,0);
    rep(j,n) {
      pos=max(0ll,j-B[j]);
      tmp[pos]++;
      if(j+B[j]+1<n) tmp[j+B[j]+1]--;
    }
    rep(j,n-1) tmp[j+1]+=tmp[j];
    rep(j,n) B[j]=tmp[j]; 
  }
  rep(i,n-1) cout<<B[i]<<' ';print(B[n-1]);
  return 0;
}
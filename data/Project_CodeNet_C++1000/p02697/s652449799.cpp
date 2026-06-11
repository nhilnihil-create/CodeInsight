#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m;cin>>n>>m;
  lvector A(m,0),B(m,0);
  rep(i,m) {A[i]=i;B[i]=2*m-1-A[i];}
  rep(i,m/2) B[i]-=2*m+1;
  rep(i,m) {
    A[i]%=n,B[i]%=n;
    while(A[i]<0) A[i]+=n;
    while(B[i]<0) B[i]+=n; 
    A[i]++,B[i]++;
    printf("%lld %lld\n",A[i],B[i]);
  }
  return 0;
}
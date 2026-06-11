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
  ll n,a,b;cin>>n;
  lvector A(n);rep(i,n) cin>>A[i];
  lvector B(A);sort(RALL(B));a=B[0],b=B[1];
  rep(i,n) {
    if(A[i]==a) print(b);
    else print(a);
  }
  return 0;
}
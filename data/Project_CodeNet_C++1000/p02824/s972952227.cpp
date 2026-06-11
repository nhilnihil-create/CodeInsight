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

ll n,m,v,p;
lvector A;

bool canwin(ll i) {
  if(n-i<=p) return true;
  ll val=A[i]+m;
  lvector B(n);
  rep(j,n) {
    if(j>=n-p+1) B[j]=m;
    else B[j]=min(val-A[j],m);
  }
  if(*min_element(ALL(B))<0) return false;
  B[i]=0;
  return accumulate(ALL(B),0ll)>=m*(v-1);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m>>v>>p;
  A.resize(n);rep(i,n) cin>>A[i];sort(ALL(A));
  ll l=-1,r=n-1,x;
  while(l+1<r) {
    x=(l+r)/2;
    if(canwin(x)) r=x;else l=x;
  }
  print(n-r);
  return 0;
}
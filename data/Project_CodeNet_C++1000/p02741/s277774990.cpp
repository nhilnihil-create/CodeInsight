//organize and stay in moment - Abhinav IIIT-A
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define f(i,x,n) for(int i=x;i<n;++i)
#define ar array
#define MAXN (int)2e5+5
#define pb push_back
int mod= 998244353;
int arr[MAXN];
int as;
void input(){
  cin>>as;
  f(i,0,as) cin>>arr[i];
}
int mod2=998244353;
void solve(){
  int a[]={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51,};
  int k; cin>>k; --k;
  cout<<a[k]<<"\n";
}
int32_t main()
{
  int t; t=1; //cin>>t;
  while(t--) solve();
  return 0;
}

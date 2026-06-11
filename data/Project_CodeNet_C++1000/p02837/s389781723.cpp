#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
int main(){int n;cin>>n;vector<int>v(n),m(n);rep(i,n){int a;cin>>a;rep(j,a){int x,y;cin>>x>>y;x--;v[i]|=y<<x;m[i]|=1<<x;}}int r=0;rep(i,(1<<n)){rep(j,n){if((i>>j)&1){int check=(i^v[j])&m[j];if(check>0)break;}if(j==n-1)r=max(r,__builtin_popcount(i));}}cout<<r<<endl;}
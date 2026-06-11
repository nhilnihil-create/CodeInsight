#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define per1(i,n) for(int i=n;i>0;i--)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vec A(n);
    rep(i,n) cin>>A[i];
    double B[n+1];
    B[0]=0;
    rep(i,n) B[i+1]=B[i]+(double)(A[i]+1)/2;
    double ans=0;
    rep(i,n-k+1) ans=max(ans,B[i+k]-B[i]);
    cout<<setprecision(10)<<ans;
}
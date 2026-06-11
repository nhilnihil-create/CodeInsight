#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
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
    int n;
    double x[8],y[8];
    cin>>n;
    rep(i,n) cin>>x[i]>>y[i];
    vec A;
    rep(i,n) A.push_back(i);
    double sum=0,b=0;
    do{
        rep(i,n-1) sum+=sqrt((x[A[i]]-x[A[i+1]])*(x[A[i]]-x[A[i+1]])+(y[A[i]]-y[A[i+1]])*(y[A[i]]-y[A[i+1]]));
        b++;
    }while(next_permutation(all(A)));
    cout<<setprecision(10)<<sum/b;
}
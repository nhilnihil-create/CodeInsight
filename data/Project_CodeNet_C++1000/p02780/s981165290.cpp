#include <bits/stdc++.h>
#define ll long long
#define pi 3.14159265358979
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
using namespace std;


int main(){
    ll n,k,a[200005],b[200005],sum=0;
    double ans;
    cin>>n>>k;
    b[0]=0;
    rep(i,n){
        cin>>a[i];
        b[i+1]=b[i]+a[i];
    }
    rep(i,n-k+1){
        if(sum<b[i+k]-b[i]){
            sum=b[i+k]-b[i];
        }
    }
    sum+=k;
    ans=sum/2.0;
    cout << fixed << setprecision(15) << ans << endl;
}
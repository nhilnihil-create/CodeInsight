#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1001001001;
const long long MOD = 1000000007;
const double EPS = 1e-10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    ll x=0,y=0,z=0;
    ll ans=1;
    for(int i=0;i<n;i++){
        ll cnt=0;
        if(x==a[i])cnt++;
        if(y==a[i])cnt++;
        if(z==a[i])cnt++;
        if(x==a[i]){
            x++;
        }else if(y==a[i]){
            y++;
            if(y>x)swap(y,x);
        }else if(z==a[i]){
            z++;
            if(z>y)swap(z,y);
            if(y>x)swap(y,x);
        }
        ans*=cnt;
        ans%=MOD;
    }
    cout<<ans<<endl;
}
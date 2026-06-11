// Hail god Yato
 
#include <bits/stdc++.h> 
using namespace std;
 
#define hs ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
const ll mod = 1000000007;
const ll INF = 1e18;
const ll MAX = 100001;
const long double epi = 0.0000001;
#define PI 3.141592653589793238
//
//
void solve(){
    long double h, m, hlen, mlen;
    cin>>hlen>>mlen>>h>>m;
    long double hour_angle = (h*60+m)/2.00;
    long double min_angle = (m)*6.00;
    long double diff = min(abs(hour_angle - min_angle), 360.00-abs(hour_angle - min_angle));
    long double ans = hlen*hlen + mlen*mlen - 2*hlen*mlen*cos(diff*PI/180.00);
    // cout<<abs(1.001);
    cout<<sqrt(ans);
}
int main(){ 
        hs;
        ll t;
        t=1;
        cout<<fixed<<setprecision(10);
        // cin>>t;
        for (int i=1; i<=t; i++){
                //cout<<"Case #"<<i<<": ";
                solve();
         }
        return 0; 
}
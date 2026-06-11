#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1LL<<60;
const ll mod = 1e9 + 7;
 
int digit(ll x) {
    if (x / 10 == 0) return 1;
    return digit(x / 10) + 1;
}
 
ll gcd(long long a,long long b) {
    if (a < b) swap(a,b);
    if (b == 0) return a;
    
    return gcd(b,a%b);
}
 
ll lcm(ll a,ll b){
    return ((a * b == 0)) ? 0 : (a / gcd(a,b) * b);
}
 
double DegreeToRadian(double degree){
    return degree * M_PI / 180.0;
}
 
 
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
 
 
///////////////////////////////////////////////////////////////////////////////////

int main(){
    ll n;
    cin >> n;
    ll ans = 0;
    ll rep = 1;
    for (ll i = 2;i * i <= n;i++){
        if (n % i != 0) continue;
        ll ex = 0;
        while(n % i == 0){
            ex++;
            n /= i;
        }
        long long cnt = 1;
        while(cnt <= ex){
            ans++;
            ex -= cnt;
            cnt++;
        }
    }
    if (n != 1) ans++;
    cout <<ans << endl;
    return 0;
}
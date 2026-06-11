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
    vector<int> a(n);
    for (int i = 0;i < n;i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int MAX = a[0];
    vector<int> dp(MAX+1);
    for (int i = 0;i < n;i++){
        dp[a[i]]++;
        for (int j = 2;a[i] * j <= MAX; j++){
            dp[a[i] * j]++;
        }   
    }

    int ans = 0;
    for (int i : a){
        if (dp[i] == 1) ans++;
    }

    cout << ans << endl;
    return 0;
}
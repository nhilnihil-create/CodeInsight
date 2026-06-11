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
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> l(n, -1);
    for (int i = 0;i < n;i++){
        cin >> a[i];
        a[i]--;
    }

    int cur = 0;
    int cnt = 0;

    while(l[cur] == -1){
        l[cur] = cnt++;
        cur = a[cur];
        if (cnt == k){
            cout << cur + 1 << endl;
            return 0;
        }
    }

    k -= l[cur];
    int cycle = cnt - l[cur];
    k %= cycle;
    for(int i = 0;i < k;i++){
        cur = a[cur];
    }

    cout << cur + 1 << endl;
    return 0;
}
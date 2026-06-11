#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define _USE_MATH_DEFINES
#include <math.h>
#define rep(i,n) for(int i = 0;i < n;i++)
#define NIL = -1;
#define all(x) x.begin(),x.end()
const ll INF = 1e9;
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

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


/////////////////////////////////////////////////////////////////////////////////////

int main() {
    int n,m; 
    long long k;
    cin >> n >> m >> k;
    vector<long long> a(n), b(m);
    vector<long long> asum(n+1), bsum(m+1);
    int ans = 0;
    asum[0] = 0, bsum[0] = 0;

    for (int i = 1;i <= n;i++){
        cin >> a[i-1];
        asum[i] = asum[i-1] + a[i-1];
    }

    for (int i = 1;i <= m;i++){
        cin >> b[i-1];
        bsum[i] = bsum[i-1] + b[i-1];
    }
    int j = m;
    for (int i = 0;i <= n;i++){
        if (asum[i] > k){
            break;
        }

        while(asum[i] + bsum[j] > k){
            j--;
        }
        ans = max(ans, i+j);
    }

    cout << ans << endl;
    return 0;
}
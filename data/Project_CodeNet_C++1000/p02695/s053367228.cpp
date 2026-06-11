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

double DegreeToRadian(double degree){
    return degree * M_PI / 180.0;
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};


/////////////////////////////////////////////////////////////////////////////////////

int N, M, Q;
int A[11];
int a[50], b[50], c[50], d[50];

int ans = 0;

void dfs(int n){
    if (n == N){
        int sum = 0;
        for (int i = 0;i < Q;i++){
            if (A[b[i]] - A[a[i]] == c[i]){
                sum += d[i];
            } 
        }

        ans = max(ans, sum);
        return;
    }

    for (int i = min(A[n], M);i <= M;i++){
        A[n+1] = i;
        dfs(n+1);
    }
}

int main(){
    cin >> N >> M >> Q;
    for(int i = 0;i < Q;i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    A[0] = 1;
    dfs(0);
    cout << ans << endl;
    return 0;

}
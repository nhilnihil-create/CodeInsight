// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1000000007;

vector<ll> F, R;

ll power(ll m, ll n){
    if(n == 0) return 1;
    if(n % 2 == 1) return m * power(m, n - 1) % INF;
    ll tmp = power(m, n/2);
    return tmp * tmp % INF;
}

void fac(int N){
    F.assign(N + 1, 1);
    R.assign(N + 1, 1);
    for(ll i = 1; i <= N; i++){
        F[i] = F[i - 1] * i % INF;
        R[i] = power(F[i], INF - 2);
    }
}

ll com(ll m, ll n){
    if(m < 0 || n < 0 || m < n) return 0;
    ll tmp = F[m];
    tmp *= R[n];
    tmp %= INF;
    tmp *= R[m - n];
    tmp %= INF;
    return tmp;
}

int main(){
    int N, K;
    cin >> N >> K;
    
    fac(N);

    for(ll i = 1; i <= K; i++){
        cout << com(K - 1, i - 1) * com(N - K + 1, i) % INF << endl; 
    }
 
}
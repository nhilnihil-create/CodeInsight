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
int N;
long long K;
vector<int> P;
vector<long long> C;

long long solve() {
    long long res = -INF;

    vector<bool> used(N, false);
    vector<vector<long long>> ss;
    for (int i = 0;i < N;i++){
        if (used[i]) continue;
        int cur = i;
        vector<long long> s;
        while (!used[cur]) {
            used[cur] = true;
            s.push_back(C[cur]);
            cur = P[cur];
        }
        ss.push_back(s);
    }

    for (auto v : ss) {
        long long M = v.size();

        vector<long long> sum(M*2+1, 0);
        for (int i = 0;i < M*2;i++) sum[i+1] = sum[i] + v[i%M];

        vector<long long> amari(M, -INF);
        for (int i = 0;i < M;i++){
            for (int j = 0;j < M;j++){
                amari[j] = max(amari[j], sum[i+j] - sum[i]);
            }
        }
        for (int i = 0;i < M;i++){
            if (i > K) continue;
            long long q = (K - i) / M;
            if (q == 0 && i == 0) continue;

            if (sum[M] > 0) res = max(res, amari[i] + sum[M] * q);
            else if (i > 0) res = max(res, amari[i]);
        }
    }
    return res;
}

int main(){
    cin >> N >> K;
    P.resize(N);
    C.resize(N);
    for (int i = 0;i < N;i++){
        cin >> P[i];
        P[i]--;
    }
    for (int i = 0;i < N;i++){
        cin >> C[i];
    }
    cout << solve() << endl;
}
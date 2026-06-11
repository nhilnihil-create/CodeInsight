#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD7 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

vector<pair<ll, ll>> prime_factorize(ll N) {
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0;
        while (N % a == 0) {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1) res.push_back({N, 1});
    return res;
}
template<typename T>
T factorial(T a){
  if(a == 2) return 2;
  return a * (factorial(a-1));
}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int now = 1;
    int broken = 0;
    for(int i = 0; i < N; i++){
        if(A[i] == now){
            now++;
        }else broken++;
    }
    if(now == 1) puts("-1");
    else cout << broken << endl;
}
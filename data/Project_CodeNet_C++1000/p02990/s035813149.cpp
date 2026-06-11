#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iomanip>
using ll = long long;
using uint = unsigned int;
using graph = std::vector<std::vector<ll>>;
using wGraph = std::vector<std::vector<std::pair<ll,ll>>>;
#define rep(i,n) for (int i=0; i < int(n); i++)

using namespace std;
ll MOD7 = 1000000007;
ll MOD9 = 1000000009;
vector<ll> InputVec(ll N){
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    return A;
}
void OutputVec(vector<ll> A){
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << ",";
    }
    cout << endl;
}
vector<vector<ll>> InputVec2d(ll H,ll W){
    vector<vector<ll>> A(H);
    for (int yi = 0; yi < H; ++yi) {
        A[yi] = vector<ll>(W);
    }
    for (int yi = 0; yi < H; ++yi) {
        for (int xi = 0; xi < W; ++xi) {
            cin >> A[yi][xi];
        }
    }
    return A;
}
vector<vector<char>> InputVec2dStr(ll H,ll W){
    vector<vector<char>> A(H);
    for (int yi = 0; yi < H; ++yi) {
        A[yi] = vector<char>(W);
    }
    for (int yi = 0; yi < H; ++yi) {
        string S;
        cin >> S;
        for (int xi = 0; xi < W; ++xi) {
            A[yi][xi] = S[xi];
        }
    }
    return A;
}
void OutputVec2d(vector<vector<ll>> A){
    for (int yi = 0; yi < A.size(); ++yi) {
        for (int xi = 0; xi < A[yi].size(); ++xi) {
            cout << A[yi][xi] << ",";
        }
        cout << endl;
    }
}
graph InputGraph(ll N,ll M){
    graph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    return G;
}
graph InputDGraph(ll N,ll M){
    graph G(N);
    for (int i = 0; i < M; ++i) {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
    }
    return G;
}
void OutputGraph(graph G){
    for (int i = 0; i < G.size(); ++i) {
        cout << i << ":";
        for (int j = 0; j < G[i].size(); ++j) {
            cout << G[i][j]<< ",";
        }
        cout << endl;
    }
}
void OutputAnswerBool(bool b,bool isUpperCase = false){
    if(b){
        if(isUpperCase){
            cout << "YES" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }else{
        if(isUpperCase){
            cout << "NO" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}

vector<ll> Factorial(ll M, ll MOD){
    vector<ll> result = vector<ll>(M + 1);
    for(int i = 0; i <= M; i++){
        if(i == 0){
            result[i] = 1;
        }else{
            result[i] = result[i-1] * i % MOD;
        }
    }
    return result;
}

vector<ll> InvFact(ll M, ll MOD){
    vector<ll> result = vector<ll>(M + 1);
    vector<ll> inv = vector<ll> (M + 1);
    result[0] = 1;
    result[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < M; i++){
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        result[i] = result[i - 1] * inv[i] % MOD;
    }
    return result;
}

ll Combination(ll n,ll k,vector<ll>& fact, vector<ll>& invFact,ll MOD){
    //nCkを計算する
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fact[n] * (invFact[k] * invFact[n - k] % MOD) % MOD;
}

int main() {
    ll N,K;
    cin >> N >> K;
    auto fact = Factorial(5000,MOD7);
    auto invFact = InvFact(5000,MOD7);
    for (int i = 1; i <= K; ++i) {
        ll res = 1;
        ll M = N - K - i + 1;
        res *= Combination(K-1,i-1,fact,invFact,MOD7);
        res *= Combination(M + i, i,fact,invFact,MOD7);
        cout << res % MOD7 << endl;
    }
}

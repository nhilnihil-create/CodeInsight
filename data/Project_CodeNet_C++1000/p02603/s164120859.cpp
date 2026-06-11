#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 2100000010;
constexpr ll INF= 2000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;
typedef pair<int,P> PP;

template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

ll mod(ll val, ll M) {
    val = val % M;
    if(val < 0) {
        val += M;
    }
    return val;
}

template<typename T>
T RS(T N, T P, T M){
    if(P == 0) {
        return 1;
    }
    if(P < 0) {
        return 0;
    }
    if(P % 2 == 0){
        ll t = RS(N, P/2, M);
        if(M == -1) return t * t;
        return t * t % M;
    }
    if(M == -1) {
        return N * RS(N,P - 1,M);
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    int N;
    cin >> N;
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    ll ret = 1000;
    for(int i = 0;i < N - 1;i++) {
        if(vec.at(i) < vec.at(i + 1)) {
            ret = ret % vec.at(i) + ret / vec.at(i) * vec.at(i + 1);
        }
    }
    cout << ret << endl;
}
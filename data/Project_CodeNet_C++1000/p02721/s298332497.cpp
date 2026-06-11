#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1000000000000000000;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

template<typename T>
T Pow(T a,T b) {
    T ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}
 
ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}
 
ll RS(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P < 0) {
        return 0;
    }
    if(P%2==0){
        ll t = RS(N, P/2, M);
        return t*t % M;
    }
    return N * RS(N, P-1, M) % M;
}

int main() {
    int N,K,C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    vector<int> L(K);
    int cnt = 0;
    for(int i = 0;i < K;i++) {
        while(S.at(cnt) == 'x' && cnt < N) {
            cnt++;
        }
        L.at(i) = cnt;
        cnt += C + 1;
    }
    vector<int> R(K);
    reverse(S.begin(),S.end());
    cnt = 0;
    for(int i = 0;i < K;i++) {
        while(S.at(cnt) == 'x' && cnt < N) {
            cnt++;
        }
        R.at(i) = N - 1 - cnt;
        cnt += C + 1;
    }
    reverse(R.begin(),R.end());
    for(int i = 0;i < K;i++) {
        if(L.at(i) == R.at(i)) {
            cout << L.at(i) + 1 << endl;
        }
    }
}
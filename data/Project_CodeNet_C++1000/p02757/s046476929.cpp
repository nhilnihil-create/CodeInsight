#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;
typedef tuple<int,int,int> TP;

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
    ll N,P;
    cin >> N >> P;
    string S;
    cin >> S;
    if(P == 2) {
        ll ret = 0;
        for(ll i = 0;i < N;i++) {
            if((S.at(i) - '0') % 2 == 0) {
                ret += i + 1;
            }
        }
        cout << ret << endl;
    }
    else if(P == 5) {
        ll ret = 0;
        for(ll i = 0;i < N;i++) {
            if((S.at(i) - '0') % 5 == 0) {
                ret += i + 1;
            }
        }
        cout << ret << endl;
    }
    else {
        reverse(S.begin(),S.end());
        map<ll,ll> ma;
        ll cnt = 0;
        for(int i = 0;i < N;i++) {
            ma[cnt]++;
            cnt += (S.at(i) - '0') * RS(10,i,P);
            cnt %= P;
        }
        ma[cnt]++;
        ll ret = 0;
        for(auto x:ma) {
            ret += x.second * (x.second - 1) / 2;
        }
        cout << ret << endl;
    }
}
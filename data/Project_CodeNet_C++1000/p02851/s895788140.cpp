#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;

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

int main() {
    int N;
    cin >> N;
    ll K;
    cin >> K;
    vector<ll> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    for(int i = 0;i < N;i++) {
        vec.at(i)--;
    }
    ll cnt = 0;
    map<ll,vector<int>> ma;
    ma[0].push_back(0);
    for(int i = 0;i < N;i++) {
        cnt += vec.at(i);
        cnt %= K;
        ma[cnt].push_back(i + 1);
    }
    ll ret = 0;
    for(auto x:ma) {
        for(int i = 0;i < x.second.size();i++) {
            auto itr = lower_bound(x.second.begin(),x.second.end(),x.second.at(i) + K);
            ll A = itr - x.second.begin();
            A--;
            ret += A - i;
        }
    }
    cout << ret << endl;
}
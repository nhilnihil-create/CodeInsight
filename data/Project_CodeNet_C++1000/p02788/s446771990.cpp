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

int N;
ll bit[1000010];

void add(int a,ll w) {
    while(a <= N) {
        bit[a] += w;
        a += a & -a;
    }
}

ll sum(int a) {
    ll ret = 0;
    while(a > 0) {
        ret += bit[a];
        a -= a & -a;
    }
    return ret;
}

int main() {
    cin >> N;
    ll D,A;
    cin >> D >> A;
    vector<P> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i).first >> vec.at(i).second;
    }
    sort(vec.begin(),vec.end());
    vector<ll> C(N);
    for(int i = 0;i < N;i++) {
        C.at(i) = vec.at(i).first;
    }
    for(int i = 0;i < 1000010;i++) {
        bit[i] = 0;
    }
    ll ret = 0;
    for(int i = 0;i < N;i++) {
        if(vec.at(i).second - sum(i + 1) * A <= 0) {
            continue;
        }
        else {
            ll cnt = (vec.at(i).second - sum(i + 1) * A + A - 1) / A;
            ret += cnt;
            auto itr = upper_bound(C.begin(),C.end(),C.at(i) + 2 * D);
            int itr2 = itr - C.begin();
            itr2++;
            add(i + 1,cnt);
            add(itr2,-cnt);
        }
    }
    cout << ret << endl;
}
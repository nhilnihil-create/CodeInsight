#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll N;
ll A[105000];
vector<ll> v;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    ll xorsum = 0;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
        xorsum ^= A[i];
    }
    for(int i = 1; i <= N; i++) {
        A[i] &= ~xorsum;
    }
    for(int i = 1; i <= N; i++) {
        ll now = A[i];
        for(int j = 0; j < v.size(); j++) {
            chmin(now, now ^ v[j]);
        }
        if(now == 0) continue;
        for(int j = 0; j < v.size(); j++) {
            chmin(v[j], v[j] ^ now);
        }
        v.push_back(now);
        sort(v.begin(), v.end(), greater<ll>());
    }
    ll tmp = 0;
    for(int i = 0; i < v.size(); i++) {
        chmax(tmp, tmp ^ v[i]);
    }
    cout << tmp * 2 + xorsum << endl;
    return 0;
}

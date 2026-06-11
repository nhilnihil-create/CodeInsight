#include <bits/stdc++.h>
#define endl "\n"
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

const long long INF = 1e18;
//const ll mod = 1000000007;
typedef pair<ll, l_l> lll;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<l_l> ans;
    ll num = (M + 1) / 2;
    for(int i = 0; i < num; i++) {
        ans.push_back({num - 1 - i, num + i});
    }
    ll rest = M - num;
    for(int i = 0; i < M - num; i++) {
        ans.push_back({2*num+rest-1-i, 2*num+rest+1+i});
    }
    for(auto tmp : ans) {
        cout << tmp.first + 1 << " " << tmp.second + 1 << endl;
    }
    return 0;
}
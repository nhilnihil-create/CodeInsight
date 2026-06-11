// 見せてやるぜ、奇跡ってやつをよぉ……
#include <iostream>
#include <array>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <complex>
#include <deque>
#include <iterator>
#include <numeric>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <limits>
#include <iomanip>
#include <functional>
#include <cassert>
using namespace std;

using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;
#define rep(i, k, n) for (ll i=k; i<(ll)n; ++i)
#define REP(i, n) rep(i, 0, n)
#define ALL(v) v.begin(),v.end()
template < class T > inline bool chmax(T& a, T b) {if (a < b) { a=b; return true; } return false; }
template < class T > inline bool chmin(T& a, T b) {if (a > b) { a=b; return true; } return false; }
#define DEBUG_VLL(vec) REP(sz, vec.size()) cerr<<vec[sz]<<(sz==vec.size()-1?'\n':' ');

const ll MOD = 1000000007;
const ll HIGHINF = (ll)1e18;

pair< vector<ll>, vector<ll> > RunLengthEncoding(vector<ll> s) {
    ll len = 1;
    vector<ll> c;
    vector<ll> l;
    s.push_back(-1);
    for (int i=1; i<s.size(); i++) {
        if (s[i] != s[i-1]) {
            c.push_back(s[i-1]);
            l.push_back(len);
            len = 1;
        } else len++;
    }
    return make_pair(c, l);
} 

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n; cin >> n;
    vll s(1LL << n); REP(i, 1LL << n) cin >> s[i];
    sort(ALL(s));
    reverse(ALL(s));
    P< vll, vll > rle = RunLengthEncoding(s);

    priority_queue< P<ll, ll> > pq;
    pq.push(make_pair(n, HIGHINF));
    REP(i, rle.first.size()) {
        V< P<ll, ll> > tmp;
        REP(j, rle.second[i]) {
            if (pq.empty()) {
                cout << "No\n";
                return 0;
            }

            P<ll, ll> q = pq.top(); pq.pop();
            // cout << q.first << ' ' << q.second << '\n';
            if (q.second <= rle.first[i]) {
                cout << "No\n";
                return 0;
            }
            for (ll k = q.first - 1; k >= 0; k--) tmp.emplace_back(k, rle.first[i]);
        }
        REP(j, tmp.size()) pq.push(tmp[j]);
    }
    cout << "Yes\n";
    return 0;
}

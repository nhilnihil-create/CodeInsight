#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <chrono>
#include <stack>
#include <string>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <cassert>
#include <tuple>
#include <iomanip>
#include <random>
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <fstream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<bool> vb;

#define pb push_back
#define fi first
#define se second
#define in insert
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define speed ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

template <class T>
istream& operator>>(istream& ss, vector<T>& v) {
    for (int i = 0; i < v.size(); i++) ss >> v[i];
    return ss;
}

template <class T> 
ostream& operator<<(ostream& ss, const vector<T>& v) {
    for (int i = 0; i < v.size(); i++) ss << v[i] << ' ';
    return ss;
}

ll binpow(ll a, ll n, ll m) {
    ll res = 1;
    while (n) {
        if (n & 1) {
            res *= a;
            res %= m;
        }
        a *= (a % m);
        a %= m;
        n >>= 1;
    }
    return res % m;
}

ll gcd(ll a, ll b) {
    return b ? gcd (b, a % b) : a;
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a,b);
}

const int mod = 1e9 + 7;
const int inf = 1e9;
const int N = 2e5 + 5;

void solve() {
    int a, b;
    cin >> a >> b;
    cout << a * b;
}

int main() {
    speed;
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
}
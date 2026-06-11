#include <algorithm>
#include <cassert>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define int long long int
#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(), (x).end()
#define capi(x) int x;cin>>x
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using vi = vector<int>;

template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(b<a){a=b;return 1;}return 0;}

#define P (1'000'000'007)

using Graph = vector<vi>;

signed main() {
    string s;
    cin >> s;

    if (s == "SUN") {
        cout << 7;
    } else if (s == "MON") {
        cout << 6;
    } else if (s == "TUE") {
        cout << 5;
    } else if (s == "WED") {
        cout << 4;
    } else if (s == "THU") {
        cout << 3;
    } else if (s == "FRI") {
        cout << 2;
    } else if (s == "SAT") {
        cout << 1;
    }

    return 0;
}

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <set>
#include <numeric>
using namespace std;
using ll = long long;
using ld = long double;

#define no "no"
#define No "No"
#define NO "NO"
#define yes "yes"
#define Yes "Yes"
#define YES "YES"
#define next '\n'
#define sp " "
#define print(x) cout << (x)
#define println(x) cout << (x) << next
#define stop return(0)
#define rep(i, n) for(int (i) = (0); (i) < (n); (++i))
#define FOR(i, start, end) for(int (i) = (start); (i) < (end); (++i))
#define foreach(elem, _list) for(auto& (elem) : (_list))
#define view(_list) foreach(e, _list){ cout << e << sp; } cout << next
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr)
#define size(s) (s).size()
#define ALL(vec) (vec).begin(), (vec).end()
#define pb(e) push_back(e)
#define INF 1e+9
#define PI acos(-1)
#define TAU PI * 2
#define EPS 0.00000001
const ll MOD = 998244353;

int main() {
    ll n, k, s;
    cin >> n >> k >> s;

    if(s == 1e+9){
        rep(i, k){
            cout << s << " ";
        }
        rep(i, n - k){
            cout << 1 << " ";
        }
    }else{
        rep(i, k){
            cout << s << " ";
        }
        rep(i, n - k){
            cout << s + 1 << " ";
        }
    }

    cout << endl;

}

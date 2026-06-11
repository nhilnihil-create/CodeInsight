#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#define PI acos(-1)
#define fs first
#define sc second
#define MAX 0x3f3f3f3f
#define debug freopen("1.in","r",stdin),freopen("1.out","w",stdout);
#define ios ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll k = 1e9 + 7;

ll N, res;
ll qpow(ll m, ll k, ll p){
    ll res = 1 % p;
    while (k){
        if (k&1) res = res * m % p;
        m = m * m % p;
        k >>= 1;
    }
    return res;
}
int main(){
    ios;
    cin >> N;
    res = ((qpow(10, N, k) % k + qpow(8, N, k) % k - (2 * (qpow(9, N, k) % k)) % k) + k) % k;
    cout << res << '\n';
    return 0;
}
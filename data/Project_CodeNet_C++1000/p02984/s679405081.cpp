#include <numeric>
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <cassert>
#include <algorithm>
#include <math.h> 
#include <set>
#include <map>
#include <utility>
#include <deque>
#include <queue>
#include <iomanip>

using namespace std;

#define ll long long int
#define rep(i, n) for(ll i = 0; i < n; i++)
#define repp(i, n) for(ll i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define riverse(v) reverse((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a)  (a).begin(),(a).end()
using vi = vector<int>;
using vs = vector<string>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vb = vector<bool>;
using vvb = vector<vb>;
const ll MOD = 1e9 + 7;
set<char> alphabet = { 'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z' };



int main() {
    int N;
    cin >> N;
    vi A(N+1);
    repp(i, N)cin >> A[i];
    vi ans(N+1);
    ll sum = 0;
    for (int i = 2; i <= N; i++) {
        if (i % 2 == 0)sum -= A[i];
        else sum += A[i];
    }
    sum -= A[1];
    sum = -sum;
    ll x = sum / 2;
    ans[1] = 2 * (A[1] - x);
    for (int i = 1; i < N; i++) {
        ans[i + 1] = A[i] - ans[i] / 2;
        ans[i + 1] *= 2;
    }
    repp(i, N)cout << ans[i] << endl;
}
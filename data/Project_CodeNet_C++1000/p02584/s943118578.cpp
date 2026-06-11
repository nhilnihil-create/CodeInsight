#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for(long long i=0; i<n; i++)
#define reps(i, s, e) for(long long i=s; i<e; i++)
#define repr(i, n) for(long long i=n-1; i>=0; i--)
#define reprs(i, s, e) for(long long i=e-1; i>=s; i--)

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll x, k, d; cin >> x >> k >> d;
    if(x < 0) x *= -1;

    double kd = double(k) * double(d);

    if(double(x) > kd){
        cout << x - k * d << endl;
        return 0;
    }

    ll cand1 = x % d;
    ll cand2 = d - cand1;

    ll n_step = x / d;
    if(n_step % 2 == k % 2){
        cout << cand1 << endl;
    }
    else{
        cout << cand2 << endl;
    }

    return 0;
}
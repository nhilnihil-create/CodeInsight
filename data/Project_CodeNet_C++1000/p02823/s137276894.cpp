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

    ll n, a, b; cin >> n >> a >> b;

    if((b - a) % 2 == 0){
        cout << (b - a) / 2;
    }
    else{
        ll cand1 = b - 1;
        ll cand2 = n - a;
        ll cand3 = n - b + 1 + (b - a - 1) / 2;
        ll cand4 = a + (b - a) / 2;

        cout << min(min(cand1, cand2), min(cand3, cand4)) << endl;
    }

    return 0;
}
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

    ll n; cin >> n;
    ll a[n];
    rep(i, n){
        cin >> a[i];
    }

    sort(a, a+n);
    reverse(a, a+n);

    queue<ll> que_gen, que_pnt;
    rep(i, n){
        que_gen.push(a[i]);
    }

    que_pnt.push(que_gen.front());
    que_gen.pop();

    ll ans = 0;
    while(!que_gen.empty()){
        ans += que_pnt.front();
        que_pnt.pop();
        que_pnt.push(que_gen.front());
        que_pnt.push(que_gen.front());
        que_gen.pop();
    }

    cout << ans << endl;


}
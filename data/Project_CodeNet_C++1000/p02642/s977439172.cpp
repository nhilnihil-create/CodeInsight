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

ll amax = 1e6;

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; cin >> n;
    ll a[n];
    set<ll> st;
    set<ll> ng;
    rep(i, n){
        cin >> a[i];
        if(st.find(a[i]) == st.end()){
            st.insert(a[i]);
        }
        else{
            ng.insert(a[i]);
        }
    }

    sort(a, a+n);

    bool is_forbidden[amax + 1];
    rep(i, amax + 1){
        is_forbidden[i] = false;
    }

    for(ll t : st){
        if(is_forbidden[t]) continue;

        ll prod = t;
        while(true){
            prod += t;
            if(prod > amax) break;

            is_forbidden[prod] = true;
        }
    }

    ll cnt = 0;
    rep(i, n){
        if(is_forbidden[a[i]]){
            continue;
        }
    
        if(!(ng.find(a[i]) == ng.end())){
            continue;
        }

        cnt++;
    }

    cout << cnt << endl;


    return 0;
}
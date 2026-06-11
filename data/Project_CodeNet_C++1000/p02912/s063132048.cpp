#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)


int main(){
    ll N, M;
    cin >> N >> M;

    ll a;
    multiset<ll, greater<ll> > A;
    rep(i, N){
        cin >> a;
        A.insert(a);
    }

    rep(i, M){
        a = *A.begin();
        A.erase(A.begin());
        a /= 2;
        A.insert(a);
    }

    ll ans = 0;
    for(multiset<ll, greater<ll> >::const_iterator it = A.begin(); it != A.end(); it++){
        ans += *it;
    }
    cout << ans << endl;

    return 0;
}



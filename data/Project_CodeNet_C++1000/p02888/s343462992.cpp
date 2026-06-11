#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    ll n;
    cin >> n;

    ll L[n];
    rep(i, n){
        cin >> L[i];
    }
    sort(L, L + n);

    ll a, b, c;
    ll ans = 0;
    rep(i, n - 2){
        for(ll j = i + 1; j < n - 1; j++){
            for(ll k = j + 1; k < n; k++){
                if(L[k] < L[i] + L[j]){
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}

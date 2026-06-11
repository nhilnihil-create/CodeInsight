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
    ll N;
    cin >> N;

    ll p = 2;
    ll e;
    ll ans = 0;
    while(p * p <= N){
        if(N % p == 0){
            e = 1;
            while(N % (ll)pow(p, e) == 0){
                N /= pow(p, e);
                ans++;
                e++;
            }
            while(N % p == 0){
                N /= p;
            }
        }
        p++;
    }
    if(N > 1){
        ans++;
    }

    cout << ans << endl;


    return 0;
}
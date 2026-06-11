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
    ll N;
    cin >> N;

    ll A;
    ll x;
    ll y;
    ll m[N + 1][N + 1];
    REP(i, N){
        REP(j, N){
            m[i][j] = -1;
        }
    }
    REP(i, N){
        cin >> A;
        rep(j, A){
            cin >> x >> y;
            m[i][x] = y;
        }
    }

    ll ans = 0;
    for(ll bit = 0; bit < (1<<N); bit++){
        ll skip = 0;
        REP(speaker, N){
            if((bit & (1<<(speaker - 1))) > 0){
                REP(target, N){
                    if(m[speaker][target] != -1 && ((bit>>(target - 1)) & 1) != m[speaker][target]){
                        skip = 1;
                        break;
                    }
                }
            }
            if(skip > 0){
                break;
            }
        }
        if(skip > 0){
            continue;
        }
        ll count = 0;
        rep(i, N){
            if((bit & (1<<i)) > 0){
                count++;
            }
        }
        if(ans < count){
            ans = count;
        }
    }

    cout << ans << endl;

    return 0;
}



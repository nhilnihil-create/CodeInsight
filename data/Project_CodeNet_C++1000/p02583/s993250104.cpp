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
    ll l[n];
    rep(i, n){
        cin >> l[i];
    }

    sort(l, l+n);

    ll cnt = 0;
    rep(i, n){
        reps(j, i+1, n){
            reps(k, j+1, n){
                if(l[k] < l[i] + l[j]){
                    if(l[i] == l[j] || l[j] == l[k] || l[k] == l[i]){
                        continue;
                    }
                    cnt++;
                }
            }
        }
    }

    cout << cnt << endl;

    return 0;
}
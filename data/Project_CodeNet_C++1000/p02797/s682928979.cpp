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

    ll n, k, s; cin >> n >> k >> s;
    ll big = 1e9;
    
    rep(i, k){
        cout << s << " ";
    }
    if(s != big){
        reps(i, k, n){
            cout << big << " ";
        }
    }
    else{
        reps(i, k, n){
            cout << 1 << " ";
        }
    }
    cout << endl;

    return 0;
}
#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <math.h> // sqrt()
#include <iomanip>
#define rep(i , n) for (int i = 1; i <= (int)(n); i++)
#define repz(i , n) for (int i = 0; i < (int) n; i++)
#define repi(i , r, n) for (int i = r; i <= (int)(n); i++)
#define repd(i , r, n) for (int i = r; i >= (int)(n); i--)


using namespace std;

int counter(int x ){
    if ( x == 0) return 0;
    return counter( x >> 1) + (x & 1);
}


int main(){
    int a[20];
    int x[20][20];
    int y[20][20];
    int n;
    int ans = 0;
    cin >> n;
    rep(i , n){
        cin >> a[i];
        rep(j , a[i]) cin >> x[i][j] >> y[i][j];
    }
    // 1 == honest , 2 == unkind
    for ( int bits = 1 ; bits < (1 << n) ; bits++){
        bool ok = true;
        rep( i  , n){
            if ( ( bits >> ( i - 1) ) & 1){
                rep( j , a[i]){
                    if ( ((bits >> (x[i][j] - 1)) & 1 ) ^ y[i][j]) ok = false;
                }
            }
            
        }
        if ( ok) ans = max( ans , counter(bits));
    }
    cout << ans << endl;
}

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
#define rep(i , n) for (int i = 1; i <= (int)(n); i++)
#define repz(i , n) for (int i = 0; i < (int) n; i++)
#define repi(i , r, n) for (int i = r; i <= (int)(n); i++)
#define repd(i , r, n) for (int i = r; i >= (int)(n); i--)

using namespace std;
/*
int main(){
    int64_t a , b , c , k , d, e;
    cin >> a >> b >> c >> k;
    rep( i , k){
        d = a;
        a = b + c;
        e = b;
        b = d  + c;
        c = e + a;
    }
    if ( abs( a - b) > pow( 10 , 18))
        cout << "Unfair" << endl;
    else cout << a - b << endl;
}
 */
int main(){
    int n, k;
    int64_t s;
    cin >> n >> k >> s;
    if ( s < pow( 10 , 9)){
        rep( i , n){
            if ( i <= k) cout << s << ' ';
            else cout << s + 1 << ' ';
        }
    }
    else{
        rep( i , n){
            if ( i <= k) cout << s << ' ';
            else cout << 1 << ' ';
        }
    }
    cout << endl;
    return 0;
    
}
#ifndef CLion
//#pragma GCC optimize ("O3")
#endif

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

#define F first
#define S second
#define pb push_back
#define ll long long
#define all(x) x.begin() , x.end()
#define rep(i,s,e) for (int i = s; i < e; ++i)
#define rev(i,s,e) for (int i = s; i > e; --i)
#define mem(a,v) memset(a , v , sizeof a)
//#define mod(x,m) ((x%m + m)%m)
using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,
        tree_order_statistics_node_update>;

const int N = 2e5 + 99 , mod = 1e9 + 7;


void Main(int cse , bool last){
    ll a , b , c, d;
    cin >> a >> b >> c >> d;
    cout << max( {a * c , a * d , b * c , b * d} );
}

int main(){

#ifndef CLion
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#endif
#ifdef CLion
    freopen( "in.txt" , "r" , stdin  );
//    freopen( "out.txt", "w" , stdout );
    clock_t st = clock();
#endif

    int t = 1;
//    cin >> t;
    for ( int cse = 1; cse <= t; ++cse ) Main(cse, cse == t);

#ifdef CLion
    clock_t en = clock();
    cout << "\n\nTime: " << fixed << (en - st - 0.0) / CLOCKS_PER_SEC;
#endif
    return 0;
}
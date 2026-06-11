#include <math.h>
#include <assert.h>
#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <functional>
#include <stack>
#include <array>
#include <random>
#include <chrono>
#include <climits>
#include <bitset>
using namespace std ;
#define rep(i, a, b) for (int i=a; i<(b); i++)
#define forn(i, a) for (int i=0; i<(a); i++)
#define repd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define ford(i,a) for (int i = (a)-1; i >= 0; i--)
#define trav(a,x) for (auto& a : x)
#define int long long
#define ii pair<int,int>
#define ar array
#define FAST_IO ios_base::sync_with_stdio(false) ;cin.tie(NULL);cout.tie(NULL)
#define ms(x,a) memset(x,(int)(a),sizeof(x))
#define sz(x) ((int)(x).size())
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define pb push_back
#define endl '\n'
#define ff first
#define ss second
//const int INF = 1e18 ;
//const int MOD = 1e9 + 7 ;
const int N = 1e6+7 ;
int d[N] ;

void solve(){
    int n ;
    cin >> n ;
    rep(i,1,N){
        for(int j = i ; j < N ; j+=i){
            d[j]++ ;
        }
    }
    int ans = 0 ;
    rep(i,1,n) ans += d[i] ;
    cout << ans << endl ;
}


int32_t main(){
    FAST_IO ;
    int t = 1 ;
//    cin >> t ;
    while(t--){
        solve() ;
    }
}

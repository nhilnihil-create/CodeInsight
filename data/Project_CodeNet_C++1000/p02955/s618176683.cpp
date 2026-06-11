#include <math.h>
#include <algorithm>
#include <set>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cstring>
#include <functional>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <chrono>
#include <climits>
using namespace std ;
#define ld long double
#define int long long
#define ii pair<int,int>
#define FAST_IO ios_base::sync_with_stdio(false) ;cin.tie(NULL);cout.tie(NULL); clock_t beg = clock()
#define dbg(x) cerr << #x << " is " << x << endl;
#define ms(x,a) memset(x,(int)(a),sizeof(x))
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define vi vector<int >
#define pb push_back
#define endl '\n'
#define ff first
#define ss second
const int N = 3e5+7 ;
const int INF = 1e18 ;
const int MOD = 1e9 + 7 ;
string s ;
int n  , k ;
vi a ;
bool f(int x){
    int cnt = 0 ;
    int sm = 0 ;
    vi v ;
    for(int i = 0 ; i < n ; i++){
        int y = a[i] % x ;
        sm += y ;
        if(y) v.pb(y) ;
    }
    if(sm == 0) return 1 ;
    sort(all(v)) ;
    deque<int> Q ;
    for(int z : v) Q.pb(z) ;
    int mov = 0 ;
    while(!Q.empty()){
        if(sz(Q) == 1) return false ;
        int f = Q.front() ;
        int b = Q.back() ;
        int extra = min(f,x-b) ;
        Q.front() -= extra ;
        Q.back() += extra ;
        if(Q.front() == 0) Q.pop_front() ;
        if(Q.back() == x) Q.pop_back() ;
        mov += extra ;
    }
    return mov <= k ;
}

void solve(){
    cin >> n >> k ;
    int sm = 0 ;
    a.resize(n) ;
    for(int i = 0 ; i < n ; i++){
        cin >> a[i] ;sm += a[i] ;
    }
    vi divs ;
    for(int i = 1 ; i*i <= sm ; i++){
        if(sm%i == 0){
            divs.pb(i) ;
            if(i*i != sm){
                divs.pb(sm/i) ;
            }
        }
    }
    sort(all(divs)) ;
    for(int i = sz(divs) -1 ; i >= 0 ; i--){
        if(f(divs[i])){
            cout << divs[i] << endl ;
            return ;
        }
    }

}

int32_t main(){
    FAST_IO ;
    int t = 1 ;
//    cin >> t ;
    while(t--){
        solve() ;
    }
    cerr << "\nExecution time: " << (clock() - beg) / 1000 << '\n';
}

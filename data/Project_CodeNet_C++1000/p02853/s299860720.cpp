#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) ((ll)(x).size())
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define prt(x) cout << (x)
#define prtl(x) cout << (x) << endl
#define rep(i,a,b) for(ll i=a; i<b; i++)
#define rrep(i,a,b) for(ll i=a; i>b; i--)
#define mp(a, b) make_pair(a, b)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vc = vector<char>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using vvc = vector<vector<char>>;
using ll = long long int;
using P = pair<long long int, long long int>;
using Map = map<long long int, long long int>;
 
int main(){
    ll x, y; cin >> x >> y;
    ll a = 0;
    if(x == 1){a += 300000;}
    else if(x == 2){a += 200000;}
    else if(x == 3){a += 100000;}
    if(y == 1){a += 300000;}
    else if(y == 2){a += 200000;}
    else if(y == 3){a += 100000;}
    if(x == 1&&y == 1){
        a += 400000;
    }
    prt(a);
}
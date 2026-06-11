#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,N) for(int i = 0; i < (N); i++)
#define erep(i,N) for(int i = N - 1; i >= 0; i--)
const ll INF = 1000000000;
//const ll MOD = 1000000007;
const ld PI = (acos(-1));
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true;} return false;}
typedef pair<int, int> pair;
bool seen[505][505];

double rad(double a) {return a * 180 / PI;}

//dpTable
//bool dp[100050];
const int MAX = 510000;
const int MOD = 1000000007;

ll RepeatSquaring(ll a, ll n, ll p){
    if(n==0) return 1;
    if(n%2==0){
        ll t = RepeatSquaring(a, n/2, p);
        return t*t % p;
    }
    return (a*RepeatSquaring(a, n-1, p))%p;
}
 
ll nCr(ll n, ll r, ll mod){
    ll mul = 1, div = 1;
    for(ll i = 0; i < r; i++){
        mul *= n - i;
        div *= i + 1;
        mul %= mod;
        div %= mod;
    }   
    return mul * RepeatSquaring(div, mod - 2, mod) % mod;
}

int main(){
    int X,Y;
    cin >> X >> Y;
    if ((X + Y) % 3 != 0) cout << 0 << endl;
    else {
        int A = (2 * X - Y) / 3,B = (2 * Y - X) / 3;
        if (A < 0 || B < 0) cout << 0 << endl;
        else {
            cout << nCr(A + B, A, MOD) << endl;
        }
    }
    return 0;
}
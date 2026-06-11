#include <bits/stdc++.h>
using namespace std;
/* #pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")*/
typedef long long ll;
const ll MAXN = 1e6 + 5;
const ll MAXD = 1e3 + 5;
const ll MOD = 1e9 + 7;
const ll MODH = 1e9 + 9;
const ll p = 41;
const long double EPS = 1e-4;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll rand(ll a, ll b) {ll c = rng(); return a+((ll)abs(c))%(b-a+1);}

int main(){
 
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);


int l,r,d;
cin >> l >> r >> d;
cout << (r / d) - (l - 1) / d;

 
} 
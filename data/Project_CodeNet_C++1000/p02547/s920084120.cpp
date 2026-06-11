#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const long long int N=2e3+30;
pair <ll,ll> d[N];
int main(){
    ll n;
    cin >> n;
    rep (i,0,n) cin >> d[i].X >> d[i].Y;
    rep (i,2,n){
        if (d[i].X == d[i].Y && d[i-1].X == d[i-1].Y && d[i-2].X == d[i-2].Y){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}


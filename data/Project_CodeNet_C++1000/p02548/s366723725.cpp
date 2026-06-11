#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
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
    ll n,sq,ans=0;
    cin >> n;
    sq = sqrt(n);
    if (sq*sq == n) sq--;
    rep (i,1,sq+1){
        rep (j,i,n){
            if (i*j < n){
                if (i!=j) ans+=2;
                else{
                    ans+=1;
                }
               // debug(i);debug(j);
            }
        }
    }
    cout << ans << endl;
}


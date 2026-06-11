#include <bits/stdc++.h> 
#define int long long
#define quickie ios_base::sync_with_stdio(false); cin.tie(NULL);
#define rep(i, a, b) for(int i=a; i<b; i++)
#define rep1(i, a, b) for(int i=a; i<=b; i++)
#define repp(i, a, b) for(int i=b-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define bn begin()
#define en end()
#define SZ(x) ((int)(x).size())
#define db double
#define mi map<int, int>
#define vi vector<int>
#define qi queue<int>
#define MI(x) power(x, mod-2)
#define test int t; cin >> t;
#define mod 1000000007LL
#define pi 3.141592653589
using namespace std;

int power(int x, int y) ;
int gcd(int a, int b) ;

signed main() {
    quickie
    int a, v, b, w, t ;
    cin >> a >> v >> b >> w >> t ;
    if(a < b) {
        if(v <= w) cout << "NO\n" ;
        else {
            int ans = b-a ;
            if(ans <= (v-w)*t) cout << "YES\n" ;
            else cout << "NO\n" ;
        }
    }
    else {
        if(v <= w) cout << "NO\n" ;
        else {
            int ans = a-b ;
            if(ans <= (v-w)*t) cout << "YES\n" ;
            else cout << "NO\n" ;
        }
    }
}

int power(int x, int y) {
    int res = 1; x %= mod;
    while (y > 0) {
        if (y & 1)
            res = (res*x) % mod;
        y = y>>1;
        x = (x*x) % mod;
    }
    return res%mod;
}

int gcd(int a,int b){
    if(a==0) return b;
    return gcd(b%a,a); 
}

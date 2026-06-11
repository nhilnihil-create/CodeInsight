#include <bits/stdc++.h>
#define int long long int
#define ll long long
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
#define mod 1000000007
#define pi 3.141592653589
using namespace std;

int power(int x, int y) ;
int gcd(int a, int b) ;

signed main() {
    quickie
    int n ;
    cin >> n ;
    if(n >= 400 && n <600) cout << 8 << "\n" ;
    else if(n >= 600 && n < 800) cout << 7 << "\n" ;
    else if(n >= 800 && n < 1000) cout << 6 << "\n" ;
    else if(n >= 1000 && n < 1200) cout << 5 << "\n" ;
    else if(n >= 1200 && n < 1400) cout << 4 << "\n" ;
    else if(n >= 1400 && n < 1600) cout << 3 << "\n" ;
    else if(n >= 1600 && n < 1800) cout << 2 << "\n" ;
    else if(n >= 1800 && n < 2000) cout << 1 << "\n" ;
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

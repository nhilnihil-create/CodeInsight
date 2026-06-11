/*
t.me/ivanesipovvpered
*/
#pragma ARCENIY_KIRILLOV_POVELITEL_KROKODILOV
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC push_options
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC pop_options
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define rng(a) a.begin(), a.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define per(i, n) for (int i = n - 1; i > -1; i--)
#define rer(i, x, n) for (int i = x; i < n; i++)
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef long double ld;

const double EPS = 1e-5;
const int mod = 1e9 + 7;
const ll INFLL = 1e18;
const int INF = 1e9;
const int maxn = 2e3 + 3;

ll gcd(ll a, ll b){
    if (b == 0ll)
        return a;
    return gcd(b, a % b);
}

ll lcm(ll a, ll b){
    return (a / gcd(a, b) )* b;
}

bool is_prime(ll a){
    if (a == 2 || a == 3 || a == 5 || a == 7) return true;
    if (a % 2 == 0 || a%3 == 0 || a%5 == 0 || a%7 == 0)
        return false;
    for (ll i = 11; i * i <= a; i += 2){
        if (a % i == 0)
            return false;
    }
    return true;
}

ll binpow(ll a, int n){
    if (a == 0)
        return 1;
    if (a % 2 == 0){
        ll q = binpow(a, n / 2);
        return (q * q)  ;
    }else return (a * binpow(a, n - 1) ) ;
}


istream& operator>>(istream &in, pair<int, int> &p) {
    in >> p.fi >> p.se;
    return in;
}

ostream& operator<<(ostream &out, pair<int, int> &p) {
    out << p.fi << " " << p.se << endl;
    return out;
}


















main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            int q = i^j;
            for (int fle = 0; fle < 30; fle++){
                if (q & (1 << fle)){
                    cout << fle + 1 << ' ';
                    break;
                }
            }
        }
        cout << endl;
    }


}

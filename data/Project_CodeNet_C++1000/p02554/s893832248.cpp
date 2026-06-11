#include <bits/stdc++.h>
using namespace std;
#define M_PI 3.14159265358979323846
#define MOD 1000000007
typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef pair<int, int> ipair;
typedef pair<ll, ll> llpair;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
    
/*
    Author: Koushik Sahu
    Created: 18 Sep 2020 09:55:59
*/

ll n;

ll binExpo(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b%2==1){
            ans *= a;
            ans %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin>>n;
    ll ans = ((((binExpo(10, n) - 2ll*binExpo(9, n))%MOD)+MOD)%MOD + binExpo(8, n))%MOD;
    cout<<ans<<"\n";
    return 0;
}
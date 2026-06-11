#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
#define GET(x) (mark[x>>5]>>(x&31)&1)
#define SET(x) (mark[x>>5]|=1<<(x&31))
#define maxL (10000000>>5)+1
#define mod 1000000007
#define vi vector<int>
#define pii pair<int, int>
#define mii map<int, int>
#define si set<int>
#define pb push_back
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> in(n);
    ll i;
    rep(i, n) cin >> in[i];
    ll money(1000), stock(0);
    rep(i, n-1) {
        if (in[i] > in[i+1]) {
            money += stock * in[i];
            stock = 0;
        } else if (in[i] < in[i+1]) {
            stock += money / in[i];
            money %= in[i];
        }
    }
    money += stock * in[n-1];
    cout << money << endl;
}

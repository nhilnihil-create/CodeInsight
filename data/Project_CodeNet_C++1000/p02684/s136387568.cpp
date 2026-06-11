#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

bool is_prime[1000010];
ll check[200010];
int main() {
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    //set<int> se;
    ll i = 0,it = 0,it2;
    while(1){
        k--;
        if(k == 0){
            cout << a[i]+1 << endl;
            return 0;
        }
        if(check[i] == 0){
            check[i] = it;
            i = a[i];
        }
        else{
            it2 = it - check[i];
            i = a[i];
            break;
        }
        it++;
    }

    ll amari = k%it2;
    while(amari--){
        i = a[i];
    }
    cout << i+1 << endl;
    //cout << (k%3) << endl;
    return 0;
}
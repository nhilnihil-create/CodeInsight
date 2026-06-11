#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

ll lcm(ll a, ll b){
    ll g = gcd(a, b);
    return (a / g) * b;
}

//重みある時
using Edge = pair<int,int>;
using Graph = vector<vector<Edge> >;

int main() {
    int n,k,ans;
    cin >> n >> k;
    if(k == 1) ans = 0;
    else ans = n-k;
    cout << ans << endl;
    return 0;
}
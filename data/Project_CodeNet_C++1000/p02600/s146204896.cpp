#include<bits/stdc++.h>
#define Rushia_mywife ios::sync_with_stdio(0);cin.tie(0);
#define rep(i,head,n) for(int i=(head);i<n;i++)
#define int long long
#define F first
#define S second
#define pb push_back
#define p2(n) (1<<(n))
#define lg2(n) __lg(n)
using namespace std;
using pii = pair<long long,long long>;
using ld = long double;
mt19937 mt_rand(time(0));
const int mod = 1000000007;
const int hnum = 998244353;
const ld PI = acos(-1);

int sc[8] = {599,799,999,1199,1399,1599,1799,1999};
int x;

void solve(){
    cin >> x;
    cout << 8-(lower_bound(sc,sc+8,x)-sc) << '\n';
}

signed main(){
    Rushia_mywife
    solve();
}
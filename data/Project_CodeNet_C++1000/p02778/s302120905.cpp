#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << '\n'
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> pi;
typedef double db;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; }
//head




void solve(){
    string s;
    cin >> s;
    int n = s.size();
    rep(i,0,n) cout << 'x';
    cout << '\n';
}

int main(void){ 
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int t; cin >> t; while (t--)
        solve();
}

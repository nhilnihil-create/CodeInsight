#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = 1; i <= n; i++)
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
using P = pair <int, int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
 
ll MOD = 1000000007;
ll INF =1<<30;



int main(){
    int n;
    cin >> n;
    vector<int>a(n+1),b(n);
    rep(i,n+1) cin >> a[i];
    rep(i,n) cin >> b[i];
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    ll cnt = 0;
    rep(i,n){
        cnt+=min(a[i],b[i]);
        if(a[i]<b[i]){
            cnt+=min(a[i+1],b[i]-a[i]);
            a[i+1] = a[i+1] - min(a[i+1],b[i]-a[i]);
        }
    }
    cout << cnt <<endl;
}

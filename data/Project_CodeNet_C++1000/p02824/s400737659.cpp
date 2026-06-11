#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define repran(i, a,b) for (int i = a; i<b;i++)
#define all(x) (x).begin(), (x).end()
#define v(T) vector<T>
#define vv(T) vector<v(T)>
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<vll> vvll;



int main()
{
    ll n, m ,v, p;
    cin >> n >> m >> v >> p;
    vll a(n), s(n+1);
    rep(i, n) cin >> a[i];
    sort(all(a));
    reverse(all(a));
    rep(i, n) s[i+1] = s[i]+a[i];
    int ans = n;
    repran(i, p, n){
        ll score = m*(p+n-i-1);
        if (a[i]+m < a[p-1]) ans--;
        else {
            score += (i-p+1)*(a[i]+m) -(s[i]-s[p-1]);
            if (score< m*v) ans--;
        }
    }
    cout << ans << endl;
}
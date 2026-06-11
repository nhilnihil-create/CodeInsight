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
    int n, k;
    cin >> n >> k;
    vi a(n);
    rep(i, n) cin >> a[i];
    rep(i, k){
        vi c(n+1, 0);
        rep(j, n){
            int l = max(0, j-a[j]);
            int r = min(n, j+a[j]+1);
            c[l]++;c[r]--;
        }
        rep(i, n) c[i+1] += c[i];
        c.pop_back();
        if (a==c) break;
        a = c;
        
    }
    rep(i, n-1) cout << a[i] << " ";
    cout << a.back() << endl;
    return 0;
}
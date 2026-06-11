#include <bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < (int) n; i++)
#define forin(i, a, b) for(int i = a; i < (int) b; i++) 
#define rofin(i, a, b) for(int i = a; i > b; i--)
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define debug(i) cout << #i << ": " << i << endl
using ll = long long;
using pii = pair<int, int>;

int n, m, v, p;
int a[1000000];

bool ok(int i) {
    int _v = max(0, v - (n - i) - (p - 1));
    ll cnt_v = 1ll * m * _v;
    int j = i - 1;
    
    while(cnt_v > 0 && j >= p) {
        if(a[i] + m - a[j] >= 0) {
            cnt_v -= a[i] + m - a[j];
        } else { break; }
        j--;
    }

    return (max(cnt_v, 0ll) + a[p-1] <= a[i] + m);
}



int main() {
    // freopen("c_input.txt", "r", stdin);
    // freopen("c_output.txt", "w", stdout);
    // freopen("c_error.txt", "r", stderr);
    crap
    cin >> n >> m >> v >> p;
    forn(i,n) { cin >> a[i]; }

    sort(a, a + n);
    reverse(a, a + n);

    int l = p - 1, r = n, mid;
    while(l+1<r) {
        mid = (l+r) / 2;
        if(ok(mid)) l = mid;
        else r = mid;
    }
    cout << (l+1) << endl;
    return 0;


}
#include <bits/stdc++.h>
 
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
 
using namespace std;
 
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    vi vec(n);
    forn(i,n) {
        cin >> vec[i];
    }
    sort(all(vec));
    reverse(all(vec));

    int l = 1;
    int r = vec[0]+1;
    int ans = INT_MAX;
    while (l<=r) {
        int mid = (l+r)/2;  
        bool ok = true;
        int cnt = 0;

        forn(i,n) {
            if (vec[i] <= mid) {
                break;
            }
            cnt += vec[i] / mid;
            if (cnt > k) {
                ok = false;
                break;
            }
        }
        if (ok) {
            ans = min(mid, ans);
            r = mid -1;
        }
        else {
            l = mid + 1;
        }
    }
    if (ans == INT_MAX) {
        ans = vec[0];
    }
    cout << ans;
    
    
    
    return 0;
} 
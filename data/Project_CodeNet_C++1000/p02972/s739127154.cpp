#include<bits/stdc++.h>
#define forr(i, a, b) for(int i = (a); i < (b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define ALL(a) (a.begin()),(a.end())
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<ll, ll> LP;
const ll LINF = 1LL<<60;
const int INF = 1001001001;
const int MOD = 1000000007;

/* --------------------------------------------------- */

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> ans(n + 1, 0);
    for(int i = n; i > 0; i--) {
        if(i > n / 2) {
            if(a[i - 1] == 1) ans[i] = 1;
        } else {
            int cnt = 0;
            for(int j = i; j <= n; j += i) cnt += ans[j];
            cnt %= 2;
            if(a[i - 1] == 1 && cnt == 0) ans[i] = 1;
            else if(a[i - 1] == 0 && cnt == 1) ans[i] = 1;
        }
    }
    int m = 0;
    rrep(i, n) m += ans[i];
    cout << m << endl;
    rrep(i, n) {
        if(ans[i] == 1) cout << i << " ";
    } 
    cout << endl;

    return 0;
}
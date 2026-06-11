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

/* --------------------------------------------------- */

int main() {
    int n;
    cin >> n;
    vector<int> L(n);
    rep(i, n) cin >> L[i];
    int ans = 0;
    rep(i, n) {
        forr(j, i + 1, n) {
            forr(k, j + 1, n) {
                if(L[i] != L[j] && L[i] != L[k] && L[j] != L[k]) {
                    if(L[i] + L[j] > L[k] && L[i] + L[k] > L[j] && L[j] + L[k] > L[i]) ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
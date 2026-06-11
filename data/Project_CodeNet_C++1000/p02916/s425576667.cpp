#include <bits/stdc++.h>
using namespace std;
void debug() {cout<<endl;}
template<typename T,typename... Args>
void debug(T x,Args... args) {cout<<x<<" ";debug(args...);}
#define forn(i,a,b) for(int i=a;i<b;++i)
#define SZ(x) int(x.size())
#define pb push_back
#define F first
#define S second
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int a[n], b[n], c[n-1];
    forn(i, 0, n) {
        cin >> a[i];
    }
    forn(i, 0, n) {
        cin >> b[i];
    }
    forn(i, 0, n-1) {
        cin >> c[i];
    }
    int ans = 0;
    forn(i, 0, n) {
        ans += b[a[i]-1];
        if (i && a[i-1]+1 == a[i]) {
            ans += c[a[i-1]-1];
        }
    }
    cout << ans << endl;
}

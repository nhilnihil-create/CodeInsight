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
    int n, l;
    cin >> n >> l;
    
    int tot = 0;
    forn(i, 0, n) {
        tot += l+i;
    }
    int mn = 1e9, ans;
    forn(i, 0, n) {
        int aux = 0;
        forn(j, 0, n) {
            if (j == i) continue;
            aux += l+j;
        }
        int d = abs(tot-aux);
        if (d < mn) {
            mn = d;
            ans = aux;
        }
    }
    cout << ans << endl;
}

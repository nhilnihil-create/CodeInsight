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
    int v[n];
    forn(i, 0, n) {
        cin >> v[i];
    }
    int ans = 0;
    forn(i, 1, n-1) {
        int aux[3] = {v[i-1], v[i], v[i+1]};
        sort(aux, aux+3);
        if (v[i] == aux[1]) ans++;
    }
    cout << ans << endl;
}

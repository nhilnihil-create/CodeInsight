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
    
    long double ans = 0.0;
    while (n--) {
        int a;
        cin >> a;
        long double x = 1.0/a;
        ans += x;
    }
    ans = 1.0/ans;
    cout << fixed << setprecision(6) << ans << endl;
}

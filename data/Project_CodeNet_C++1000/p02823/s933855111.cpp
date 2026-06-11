#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);
#define FOR(i,s,n) for(int i = (s); i < (n); i++)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) for(int i = (n); i >= 0; i--)
#define ALL(n) (n).begin(), (n).end()
#define RALL(n) (n).rbegin(), (n).rend()
#define ATYN(n) cout << ( (n) ? "Yes":"No") << '\n';
#define CFYN(n) cout << ( (n) ? "YES":"NO") << '\n';
#define OUT(n) cout << (n) << '\n';
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(void)
{
    IOS
    ll N,A,B;
    cin >> N >> A >> B;

    if ( (B-A) %2 == 0 ) {
        OUT((B-A)/2)
    } else {
        ll ans = max(B-1,N-A); 
        // A=1
        ll lb = B- (A-1);
        ans = min(ans,(lb-1-1)/2+A);

        ll ra = A+ N-B;
        ans = min(ans,(N-ra-1)/2+N-B+1);

        cout << ans << '\n';
    }

    return 0;
}

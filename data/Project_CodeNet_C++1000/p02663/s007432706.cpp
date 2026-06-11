#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h1,m1;
    cin >> h1 >> m1;
    int h2,m2;
    cin >> h2 >> m2;
    int v1=h1*60+m1;
    int v2=h2*60+m2;
    int k;
    cin >> k;
    db(max(0,v2-v1-k))

    return 0;
}

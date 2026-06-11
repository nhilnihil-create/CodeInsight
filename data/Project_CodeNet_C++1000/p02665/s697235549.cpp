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
#define MAXN 100005

ll a[MAXN],ac[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<=n;i++)
        cin >> a[i];

    ac[n]=a[n];
    for(int i=n-1;i>=0;i--)
        ac[i]=ac[i+1]+a[i];

    ll res=0;
    ll po=1;
    for(int i=0;i<=n;i++)
    {
//        cout << po << ' ' << a[i] << '\n';
        po=min(po,ac[i]);
        res+=po;
        po-=a[i];
        if(po<0)
        {
            res=-1;
            break;
        }
        po*=2;
    }

    db(res)
    return 0;
}
/**
3
0 1 1 2
4
0 0 1 0 2
**/

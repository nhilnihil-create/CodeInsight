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
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int a[2][MAXN];
int base[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> base[i];
        if(i)
            a[0][i]=base[i]-base[i-1];
        else
            a[0][i]=base[i];
    }

    int cont=0;
    bool acc=0;
    while(cont<k)
    {
        int act=cont&1;
        int pp=1-act;
        bool stop=(a[act][0]==a[pp][0]);
        a[pp][0]=0;
        for(int i=1;i<n;i++)
        {
            a[act][i]+=a[act][i-1];
            stop&=(a[act][i]==a[pp][i]);
            a[pp][i]=0;
        }
        if(stop && cont)
        {
            acc=1;
            break;
        }
        for(int i=0;i<n;i++)
        {
            int ini=max(0,i-a[act][i]);
            int fin=min(n-1,i+a[act][i]);
            a[pp][ini]++;
            a[pp][fin+1]--;
        }

        cont++;
    }

    if(!acc)
        for(int i=1;i<n;i++)
            a[cont&1][i]+=a[cont&1][i-1];

    for(int i=0;i<n;i++)
        cout << a[cont&1][i] << ' ';
    cout << '\n';

    return 0;
}
/**
1 1
0
**/

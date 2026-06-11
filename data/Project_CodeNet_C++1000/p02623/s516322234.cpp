#include <bits/stdc++.h>  

using namespace std;

typedef long long ll;

#define REP(i, n) for (int i = 0; i < int(n); i++)
#define REPD(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, a, b) for (int i = a; i < int(b); i++)
#define FORD(i, a, b) for (int i = b - 1; i >= int(a); i--)
#define WRAP(y, x, h, w) (0 <= y && y < h && 0 <= x && x < w)

#define ALL(x) (x).begin(), (x).end()

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}
int dx[4] ={ 1, 0, -1, 0 };
int dy[4] ={ 0, 1, 0, -1 };

int main()
{
    int n, m, k;
    cin>>n>>m>>k;
    vector<ll> va(n);
    REP(i, n)
        cin>>va[i];
    vector<ll> vb(m);
    REP(i, m)
        cin>>vb[i];
    vector<ll> va2=va;
    FOR(i, 1, n)
        va2[i]+=va2[i-1];
    vector<ll> vb2=vb;
    FOR(i, 1, m)
        vb2[i]+=vb2[i-1];
    int idxb=m-1;
    int ans=0;
    REP(i, n+1) {
        if (i==0) {
            idxb=distance(vb2.begin(), upper_bound(ALL(vb2), k))-1;
            ans=idxb+1;
        }
        else {
            while (idxb>=0&&va2[i-1]+vb2[idxb]>k) {
                idxb--;
            }
            if (va2[i-1]>k)
                break;
            ans=max(ans, i+idxb+1);
        }
    }
    cout<<ans<<endl;
}
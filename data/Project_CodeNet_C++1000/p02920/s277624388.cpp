#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pii pair<int,int>
#define pll pair<ll, ll>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define ppi pair<pii,int>
#define pip pair<int,pii>
#define pdd pair<double, double>
#define f first
#define s second
#define MOD 1000000007
#define mkp make_pair
#define M_PI 3.14159265358979323846
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define LOR(i,l,r) for (ll i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)
#define LORD(i,r,l) for (ll i=r;i>=l;i--)
#define INF 1000000000
#define CL(x) memset(x,0,sizeof(x))
#define DEB(x) cout << #x << " : " << x << '\n'
#define ALL(x) x.begin(), x.end()
#define SZ(x) x.size()
#define UI(x) (int)(x-'A')
#define LI(x) (int)(x-'a')
typedef long long ll;

#define MXN 1000005
int N, M;
int A[MXN];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    M = (1<<N);
    FOR(i,0,M-1)cin>>A[i];
    sort( A, A+M, greater<int>() );

    int now = 0;
    priority_queue< int, vector<int> > pq;
    pq.push( N );

    while( now < M )
    {
        int cnt = 1;
        while( now+1<M && A[now+1]==A[now] )now++,cnt++;

        if( cnt>pq.size() )
        {
            cout<<"No\n";
            return 0;
        }

        vector<int> V;
        FOR(i,1,cnt)
        {
            V.pb( pq.top() );
            pq.pop();
        }
        for(int vi : V)
        {
            FOR(i,0,vi-1)pq.push(i);
        }

        now++;
    }

    cout<<"Yes\n";

    return 0;
}


#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll a,b,m,A[300001],B[300001],minim=1e18;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b>>m;
    for(int i=1;i<=a;i++)
        cin>>A[i];
    for(int i=1;i<=b;i++)
        cin>>B[i];
    for(int i=1;i<=m;i++)
    {
        ll x,y,c;
        cin>>x>>y>>c;
        ll suma=A[x]+B[y]-c;
        minim=min(minim,suma);
    }
    sort(A+1,A+a+1);
    sort(B+1,B+b+1);
    minim=min(minim,A[1]+B[1]);
    cout<<minim;
    return 0;
}

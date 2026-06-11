// Bismillah .Ya Allah...
#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef pair<int,int> PII;
const int mod = 1e9+7,INF = 1e9;
const ll mx = 1e18;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    ll x,y;
    sort(a,a+n);
    sort(b,b+n);
    if(n&1)
    {
        x = a[n/2];
        y = b[n/2];
    }
    else
    {
        x = a[n/2-1]+a[n/2];
        y = b[n/2-1]+b[n/2];
    }
    cout<<y-x+1<<endl;
    return 0;
}

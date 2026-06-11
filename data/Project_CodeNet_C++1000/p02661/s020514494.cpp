#include<bits/stdc++.h>
using namespace std;
#define light ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define cases() ll t;cin>>t;while(t--)
#define all(c) c.begin(),c.end()
#define PI 3.14159265358979323846
const ll MAX = 1e5+5;
const ll INF = 1e18;
const ll MOD = 1e9+7;

int main()
{
    int i,j,k,l,p,q,x,y,n;
    cin >> n;
    vector<int> a,b;
    for(i=0;i<n;i++)
    {
        cin >> x >> y;
        a.pb(x);
        b.pb(y);
    }
    sort(all(a));sort(all(b));
    if(n%2==0)
    {
        x = (n/2)-1;y = n/2;
        p = a[x]+a[y];q = b[x]+b[y];
    }
    else
    {
        y = n/2;
        p = a[y];q = b[y];
    }
    cout << q-p+1;
}
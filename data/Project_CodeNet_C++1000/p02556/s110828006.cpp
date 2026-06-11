#include <bits/stdc++.h>
using namespace std;
#define fastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define what_is(x) cerr << #x << " = " << x << endl;
#define eps 1e-15
#define f first
#define s second
typedef long long ll;
int main()
{
    fastIO
    int n;
    cin>>n;

    vector<ll>v;
    vector<ll>w;
    ll x,y;
    for (int i=0; i<n; ++i)
    {
        cin>>x>>y;
        v.push_back(x+y);
        w.push_back((x-y));
    }
    sort(v.begin(),v.end());
    sort(w.begin(),w.end());

    cout<<max(v[n-1]-v[0],w[n-1]-w[0]);


}

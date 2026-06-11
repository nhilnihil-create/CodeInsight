#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()

int main()
{
    ll i,j,n;
    cin>>n;
    vector<int> a,b;
    for(i=0;i<n;i++)
    {
        ll x,y;
        cin>>x>>y;
        a.push_back(x-y);
        b.push_back(x+y);
    }
    ll mna = *min_element(all(a));
    ll mxa = *max_element(all(a));
    ll mnb = *min_element(all(b));
    ll mxb = *max_element(all(b));
    ll ans = max(mxa - mna, mxb - mnb);
    cout<<ans<<"\n";
}
#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define hell 1000000007
#define PI 3.14159265358979323846
using namespace std;

int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    //int c=0;
    while(t--) {

       ll n,i,j,k;
       vector<pair<ll,ll> >v;
       cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>j>>k;
            v.pb({j,k});
        }
        ll f=0;
        for(i=0;i<n-2;i++)
        {
            if(v[i].first==v[i].second && v[i+1].first==v[i+1].second && v[i+2].first==v[i+2].second)
            {
                f=1;
                break;
            }
        }
        if(f)
            cout<<"Yes";
        else
            cout<<"No";
    }

}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007


int main()
{
    int t=1;
    //cin>>t;

    while( t-- )
    {
        ll n;
        cin>>n;

        vector<ll> arr(n);
        map<ll,bool> ch;

        for(ll i=0;i<n;i++)
            cin>>arr[i] , ch[arr[i]] = 0;

        sort(arr.begin() , arr.end());

        for(ll i=0;i<n;i++)
        {
            if(ch[arr[i]])
                continue;

            for(ll j=2;arr[i]*j<=arr[n-1];j++)
                ch[arr[i] * j] = 1;
        }

        ll ans = 0;

        for(int i=0;i<n;i++)
        {
            if(ch[arr[i]])
                continue;
            if(i>0 && arr[i-1]==arr[i])
                continue;
            if(i<n-1 && arr[i+1]==arr[i])
                continue;
            ans++;
        }

        cout<<ans;
    }
    return 0;
}

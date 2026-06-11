#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define ld long double
#define clr(arr) memset(arr,0,sizeof(arr))
#define nn '\n'

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
//    cin>>t;
    while(t--)
    {
        ll tk = 1000, x = 0;
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0; i<n; i++) cin>>arr[i];
        for(ll i=1; i<n; i++)
        {
            if(arr[i]>arr[i-1])
            {
                ll x = tk/arr[i-1];
                tk -= (x*arr[i-1]);
                tk += (x*arr[i]);
            }
        }
        cout<<tk<<endl;
    }

    return 0;
}



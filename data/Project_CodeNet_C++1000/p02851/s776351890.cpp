#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int n,k;
cin>>n>>k;
int arr[n];
for(int i=0;i<n;i++)
    cin>>arr[i];
    for(int i=0;i<n;i++)
        arr[i]-=1;
        arr[0]%=k;
    for(int i=1;i<n;i++)
    {
        arr[i]+=arr[i-1];
        arr[i]%=k;
    }

    map<int,vector<int> > mp;
     mp[0].pb(0);
    for(int i=0;i<n;i++)
        {
            mp[arr[i]].pb(i+1);
        }
    int ans=0;
    map<int,vector<int> > ::iterator it=mp.begin();
    for( ;it!=mp.end();it++)
    {
        vector<int> a=it->second;
        int i=0,j=1;
        int prev=a[0];
        while(j<a.size())
        {
            if(a[j]-prev<k)
            {   ans+=j-i;

                j++;
            }
            else
            {
                while(a[j]-a[i]>=k)
                {
                    i++;
                }
                prev=a[i];
            }
        }


    }
    cout<<ans<<endl;
return 0;
}

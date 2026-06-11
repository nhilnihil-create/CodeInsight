#include<bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define int ll
#define pb push_back
#define setbits(x)          __builtin_popcountll(x)
#define endl "\n"
typedef long long ll;
void solve()
{
    int n;
    cin>>n;
    pair<int,int> arr[n];
    for(int i=0;i<n;i++)
    {
    cin>>arr[i].ff>>arr[i].ss;
    }
    int maxi=INT_MIN,mini=INT_MAX;
    sort(arr,arr+n);
    int i=0;
    int prev=arr[0].ff;
    int ans=0;
    while(i<n)
    {
        int j=i;
        int cm=INT_MIN,cmi=INT_MAX;
        while(i<n&&arr[i].ff==arr[j].ff)
        {
            cm=max(arr[i].ss,cm);
            cmi=min(cmi,arr[i].ss);
            i++;
        }
        maxi=max(maxi+arr[j].ff-prev,cm);
        mini=min(mini-arr[j].ff+prev,cmi);
       ans=max(ans,max(abs(mini-cm),maxi-cmi));
       prev=arr[j].ff;
    }
    cout<<ans<<endl;













}
int32_t main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
 solve();
    return 0;
}


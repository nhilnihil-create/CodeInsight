#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define eb emplace_back
#define precision(n) cout << fixed << setprecision(n);
#define fast {ios_base::sync_with_stdio(false);cin.tie(NULL);}
int main()
{
    int n;
    cin>>n;
    // vector<int>v;
    int a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];

    }
    int ans=0;
    int cnt=0;
    for(int i=0;i<n-1;i++)
    {
        if(a[i]>=a[i+1])
        {
            cnt++;
            ans=max(ans,cnt);
        }
        else
        {
        // ans=max(ans,cnt+1);
         cnt=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}



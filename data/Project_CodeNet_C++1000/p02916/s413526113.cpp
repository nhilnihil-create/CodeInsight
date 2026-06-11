#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    int n;
    cin>>n;
    int eo[n],sp[n],asp[n-1];
    for(int i = 0;i<n;i++)
    {
        cin>>eo[i];
    }
    for(int i = 0;i<n;i++)
    {
        cin>>sp[i];
    }
    for(int i = 0;i<n-1;i++)
    {
        cin>>asp[i];
    }
    int ans = 0;
    for(int i = 0 ;i<n;i++)
    {
        ans = ans + sp[eo[i]-1];
        if(i>0&&eo[i] == eo[i-1]+1)
        {
            ans = ans + asp[eo[i-1]-1];
        }
    }
    cout<<ans;
    return 0;
}
#include <bits/stdc++.h>
#define int long long int
using namespace std;

signed main() {
    int n,t;
    cin>>n;
    map<int,int> m;
    map<int,int> m2;
    int arr[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>t;
        arr[i]=t;
        m2[i-t]++;
        m[t+i]++;
    }
    int ans=0;
    for(int i=1;i<=n;i++)
    {
       
        //cout<<m2[i + arr[i]]<<endl;
        ans += m2[i + arr[i]];
        
    }
    cout<<ans;
    return 0;
}
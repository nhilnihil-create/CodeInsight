#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=2e5+9;
 
int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k,ans=0,a[N];
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<k;i++)ans+=a[i];
    cout<<ans;
    
    
    
    
    
}

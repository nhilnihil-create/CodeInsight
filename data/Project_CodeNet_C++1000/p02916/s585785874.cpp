#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define Q int tt,qq; cin>>tt ;for(qq=1;qq<=tt;qq++)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main()
{
    int n;
    cin>>n;
    vector<int>a(n),b(n),c(n-1);
    for(int i=0;i<n;i++)    cin>>a[i];
    for(int i=0;i<n;i++)    cin>>b[i];
    for(int i=0;i<n-1;i++)  cin>>c[i];
    for(int i=0;i<n;i++){
        a[i]=a[i]-1;
    }
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=b[a[i]];
        if(a[i+1]-a[i]==1)
            sum+=c[a[i]];
    }
    cout<<sum;

}

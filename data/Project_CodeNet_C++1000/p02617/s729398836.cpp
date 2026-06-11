#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
    int n,a,b;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;++i)
        ans+=(ll)i*(n-i+1);
    for(int i=1;i<n;++i)
    {
        cin>>a>>b;
        if(a>b)
            swap(a,b);
        ans-=(ll)(a-1+1)*(n-b+1);
    }
    cout<<ans<<endl;
}

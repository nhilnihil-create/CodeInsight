#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
#define f first
#define s second
using namespace std;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)1e9+7;
const double eps=1e-9;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> v(n+1),ans(n+1),sum(n+1),ans2;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=n;i;i--){
        for(int j=i+i;j<=n;j+=i)
            sum[i]+=ans[j];
        sum[i]%=2;
        if(v[i]!=sum[i])
            ans[i]=1;
    }
    for(int i=1;i<=n;i++)
        if(ans[i])
            ans2.push_back(i);
    cout<<ans2.size()<<"\n";
    prArr(ans2,ans2.size());
    return 0;
}

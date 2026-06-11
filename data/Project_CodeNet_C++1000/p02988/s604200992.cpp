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
    int n,ans=0;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=1;i<n-1;i++)
        ans+=((v[i-1]<v[i]&&v[i]<v[i+1])||(v[i-1]>v[i]&&v[i]>v[i+1]));
    cout<<ans;
    return 0;
}


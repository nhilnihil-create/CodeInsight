#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
#define f first
#define s second
using namespace std;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)1e9+7;
const double eps=1e-9;
int dist(vector<int> a,vector<int> b);
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,d,d2,tmp,ans=0;
    cin>>n>>d;
    vector<vector<int>> p(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<d&&cin>>tmp;j++)
            p[i].push_back(tmp);
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            d2=dist(p[i],p[j]),
            ans+=((int)sqrt(d2)*(int)sqrt(d2))==d2;
    cout<<ans;
    return 0;
}

int dist(vector<int> a,vector<int> b)
{
    int ret=0;
    for(int i=0;i<a.size();i++)
        ret+=(a[i]-b[i])*(a[i]-b[i]);
    return ret;
}

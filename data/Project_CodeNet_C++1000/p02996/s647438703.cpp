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
    int n,ctr=0;
    cin>>n;
    vector<pair<int,int>> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i].s>>v[i].f;
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++)
    {
        if(ctr+v[i].s>v[i].f)
            return cout<<"No",0;
        ctr+=v[i].s;
    }
    cout<<"Yes";
    return 0;
}


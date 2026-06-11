#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
using namespace std;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)1e9+7;
bool seen[101];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x,n,tmp,ans1,ans2;
    cin>>x>>n;
    for(int i=0;i<n&&cin>>tmp;i++)
        seen[tmp]=1;
    for(int i=x;i<200;i++)
        if(!seen[i]){ans1=i;break;}
    for(int i=x;i>=0;i--)
        if(!seen[i]){ans2=i;break;}
    cout<<(ans1-x<x-ans2?ans1:ans2);
    return 0;
}

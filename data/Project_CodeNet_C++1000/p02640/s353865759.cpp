#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
using namespace std;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)1e9+7;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x,y;
    cin>>x>>y;
    if(y%2)
        return cout<<"No",0;
    int b=(y-2*x)/2,a=x-b;
    if(a>=0&&b>=0)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}

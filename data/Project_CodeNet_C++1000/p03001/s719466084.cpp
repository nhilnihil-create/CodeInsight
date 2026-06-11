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
    long long area,w,h,x,y;
    cin>>w>>h>>x>>y;
    cout<<((double)w*h/2)<<" "<<(x*2==w&&y*2==h);
    return 0;
}


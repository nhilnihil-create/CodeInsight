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
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<b-a+1-(b/c-(a-1)/c+b/d-(a-1)/d-b/(c*d/__gcd(c,d))+(a-1)/(c*d/__gcd(c,d)));
    return 0;
}


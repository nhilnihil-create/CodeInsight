#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
using namespace std;
int main()
{
    ll s;
    cin>>s;
    int lim=1e9;
    int x=s/lim;if(s%lim) x++;
    int b=s/x;if(s%x) b++;

    int y=1ll*x*b-s;
    printf("%d %d %d %d %d %d",0,0,x,y,1,b);
    return 0;
}

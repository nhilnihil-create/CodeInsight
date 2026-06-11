#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
typedef long long ll;

ll a,b,c,d,ans;
int main()
{
    cin>>a>>b>>c>>d;
    ans=max(max(a,b)*max(c,d),min(a,b)*min(c,d));
    ans=max(ans,max(a,b)*min(c,d));
    ans=max(ans,min(a,b)*max(c,d));
    cout<<ans<<endl;
    return 0;
}
////刷题！！！！！！！！！！！！！！！！

#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof a)
#define MAX 100005
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans[4]={a*c,a*d,b*c,b*d};
    sort(ans,ans+4);
    cout<<ans[3];
}
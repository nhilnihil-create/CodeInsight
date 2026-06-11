#include<cstdio>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    vector<ll> v(a),s(a+1,0);
    for(int i=0;i<a;i++)
    {
        scanf("%lld",&v[i]);
        v[i]--;
        s[i+1] = (s[i]+v[i]+b)%b;
    }

    map<int,int> mp;
    ll ans=0;
    for(int i=0;i<=a;i++)
    {
        if(i-b>=0)mp[s[i-b]]--;
        ans += mp[s[i]];
        mp[s[i]]++;
    }
    printf("%lld\n",ans);
    return 0;
}
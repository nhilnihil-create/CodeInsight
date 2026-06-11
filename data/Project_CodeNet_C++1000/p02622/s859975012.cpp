#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
const ll  big =1e3+5;
pair <ll,ll> p1[big],p2[big];
ll a[big][big];
int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

string s,t;
cin>>s>>t;
ll ans=0,n=s.size();
for(int i=0;i<n;++i){
    if(s[i]!=t[i])ans++;
}
cout<<ans;
    return 0;
}
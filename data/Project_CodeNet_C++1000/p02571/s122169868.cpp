#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mxn=2e5+3,du=1e9+7;
string a,b;
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin>>a>>b;
    int ans=du;
    for (int i=0;i<a.size()-b.size()+1;i++)
    {
        int cnt=0;
        for (int j=0;j<b.size();j++)
        {
            if (a[i+j]==b[j]) cnt++;
        }
        ans=min(ans,(int)b.size()-cnt);
    }
    cout<<ans;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define all(x) begin(x),end(x)

int mod = 1e9+7;
int inf = 4e18;
const int N = 5e5+5;
		
signed main()
{
    flash
    int tt = 1;
    //cin>>tt;
    while(tt--)
    {
		string s = "ACL";
		int n;
		cin>>n;
		string ans = "";
		while(n--)
		{
			ans+=s;
		}
		cout<<ans;
    }
    return 0;
}

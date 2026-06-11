#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	string s,t;
    int ans=0;
    cin>>s>>t;
    for (int i = 0; i < SZ(s); i++)
    {
        if(s[i]!=t[i]) ans++;
    }
    
   cout<<ans;
   return 0;
}

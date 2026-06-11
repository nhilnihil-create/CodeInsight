#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n;
		cin>>n;
	 ll ans=0;
	for (int i = 1; i <= n; ++i)
		{
			if(i%3!=0&&i%5!=0){
				ans+=i;	
			}
			
		}	
    cout<<ans;
   return 0;
}

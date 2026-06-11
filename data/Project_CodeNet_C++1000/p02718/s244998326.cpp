#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define SZ(X) ((int)(X).size())
#define endl "\n";
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n,m,a[10001],cnt=0;
	long long sum=0;
	cin>>n>>m;
	for (int i = 0; i < n; ++i)
		{
			cin>>a[i];
			sum+=a[i];
		}	
	for (int i = 0; i < n; ++i)
	{
		if((a[i]*4*m)>=sum){
				cnt++;
			}
	}

    if(cnt>=m) cout<<"Yes"; else cout<<"No";
   return 0;
}

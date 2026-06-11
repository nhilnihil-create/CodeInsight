#include<bits/stdc++.h>
#define endl '\n'
#define int long long
 
using namespace std;
 
int32_t main ()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	int n;
	cin>>n;
	bool ans=0;
	int count=0;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		if(x==y)count++;
		else count=0;
		if(count>=3)ans=1;
	}	

	if(ans)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	return 0;
}

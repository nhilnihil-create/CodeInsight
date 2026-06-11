#include<bits/stdc++.h>
using namespace std;
#define FOR(x,i,e) for(int x=i; x<e; x++)
#define int long long int
 
signed main()
{
	int k;
	cin >>k;
	int p=7;
	FOR(i,0,k+1){
		if(p%k==0)
		{
			cout<<i+1<<endl;
			return 0;
		}
		p=(p*10+7)%k;
 
	}
	cout<<"-1"<<endl;
	return 0;
}
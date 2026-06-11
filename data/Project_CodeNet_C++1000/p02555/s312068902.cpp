#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<map>
#include<set> 
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<math.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int main()
{
	ll S[2005]={0,0,0,1,1};
	int s;
	cin>>s; 
	for(int i=4;i<=s;i++)
	{
		S[i]=(S[i-1]+S[i-3])%mod;
	}
	cout<<S[s]<<endl;
	return 0;
}

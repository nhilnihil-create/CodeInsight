#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define mod 1000000007
#define exp pow(10,-9)
#define F first
#define S second
#define PB push_back 
#define MP make_pair
#define daman ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define lowercase(str) transform(str.begin(), str.end(), str.begin(), ::tolower);
#define uppercase(str) transform(str.begin(), str.end(), str.begin(), ::toupper);
main(){
	int n;
	cin>>n;
	
	int ans[10005] = {0};
	for(int i=1;i<=101;i++)
	{
		for(int j=1;j<=101;j++)
		{
			for(int k=1;k<=101;k++)
			{
				int ind = i*i + j*j + k*k + i*j + j*k + k*i;
				if(ind < 10005)
					ans[ind]++;
			}
		}
	}
	
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<"\n";
}
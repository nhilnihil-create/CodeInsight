#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9;
int main()
{
	int N;
	scanf("%d",&N);
	
	int Max1 = mod*-1,Min1 = mod;
	int Max0 = mod*-1,Min0 = mod;
	for(int i = 1;i <= N;++i)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		
		Max1 = max(Max1,x+y);
		Min1 = min(Min1,x+y);
		Max0 = max(Max0,x-y);
		Min0 = min(Min0,x-y); 
	}
	int ans = max((Max1 - Min1) , (Max0 - Min0));
	return printf("%d",ans),0;
} 
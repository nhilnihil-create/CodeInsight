#include<bits/stdc++.h>
using namespace std;
#define mem(a) memset(a,0,sizeof(a))
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define ll long long
//不要再爆long long了！！！！！！！！不要再爆long long了！！！！！！！ 

int main()
{
	int s=0,a,b;
	int N;
	cin>>N;
	bool flag=0;
	while(N--)
	{
		cin>>a>>b;
//		s+=a==b;
		if(a==b)
		{
			s++;
			if(s>2)flag=1;
		}
		else s=0;
	}
//	puts(s>2?"Yes":"No");
	puts(flag?"Yes":"No");
	return 0;
}
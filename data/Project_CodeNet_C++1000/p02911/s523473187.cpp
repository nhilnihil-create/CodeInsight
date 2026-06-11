#include <iostream>
using namespace std;
int main()
{
	long long n ,m ,k ,score[100005] ,t;	
	while(cin>>n>>m>>k)
	{
		for(int i=1 ;i<=n ;i++) score[i] = m;
		for(int i=1 ;i<=k ;i++) cin>>t ,score[t]++;
		for(int i=1 ;i<=n ;i++) 
		{
			score[i]-=k;
			if(score[i]>0)cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
} 
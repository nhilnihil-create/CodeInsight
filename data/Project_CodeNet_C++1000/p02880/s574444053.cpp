#include "bits/stdc++.h"
using namespace std;

int n;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		if(n%i!=0) continue;
		int d1=i,d2=n/i;
		if(max(d1,d2)<10) return 0 * printf("Yes");
	}
	printf("No");
}
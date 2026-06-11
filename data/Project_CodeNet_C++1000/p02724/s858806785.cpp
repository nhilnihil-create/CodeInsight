#include <bits/stdc++.h>
using namespace std;
int x,ans;
int main()
{
	scanf("%d",&x);
	ans=(x/500)*1000+(x%500)/5*5;
	printf("%d",ans);
}
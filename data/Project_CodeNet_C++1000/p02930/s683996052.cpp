#include <iostream>
using namespace std;
int get(int x)
{
	int ret=0;
	while (!(x&(1<<ret)))
	ret++;
	return ret+1;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		printf("%d ",get(j-i));
		printf("\n");
	}
}
#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int a,b,ans,ans2;
	double ans3;

	cin >> a >> b;

	ans = a/b;
	ans2 = a%b;
	ans3 = (double) a/b;

	cout << ans << " " << ans2 << " " ;
	printf("%f",ans3);

	return 0;
}
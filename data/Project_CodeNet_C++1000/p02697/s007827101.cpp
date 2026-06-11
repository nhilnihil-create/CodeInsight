#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n,m,x,y,flag;
	cin >> n >> m;
	x=1,y=n,flag=0;
	if(n&1)
	for(int i=1;i<=m;i++)
		cout << i << " " << n-i << "\n";
	else
	for(int i=1;i<=m;i++)
	{
		if(y-x<=n/2&&!flag)
		{
			--y;
			flag=1;
		}
		cout << x << " " << y << "\n";
		++x,--y; 
	}
	return 0;
}
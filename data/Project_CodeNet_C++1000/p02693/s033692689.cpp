#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin >> a>>b>>c;
	for (int i = b; i <= c; i++)
	{
	
		if (i%a == 0) {
			cout << "OK";
			exit(0);
		}
	}
	cout << "NG";
    return 0;
}


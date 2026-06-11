#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	
	if(a<10)
		cout << 100*(10-a)+b;
else
		cout << b;
		
return 0;
}
#include <iostream>
#include<string>
using namespace std;
int main()
{
	int n,arr[100],x=0;
	cin >> n;
	for (int i = 1; i <=n; i++) {
		cin >> arr[i];
	}
	for(int i = 1; i <= n; i++) {
		if (i % 2 == 1 & arr[i] % 2 == 1)x++;
	}
	cout << x;
	return 0;
}

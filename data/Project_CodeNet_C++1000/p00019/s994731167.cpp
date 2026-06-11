#include <iostream>

using namespace std;

int main()
{
	int n;
	long long s = 1;
	cin >> n;
	
	for (int i = 0; i < n; i++){
		s *= (n - i);
	}
	
	cout << s << endl;
	return (0);
}
#include <iostream>
#include <string>
using namespace std;

int n, a[200200], c[200200]; long long r;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		r += c[a[i]]++;
	}

	for (int i = 0; i < n; i++){
		r -= --c[a[i]];
		cout << r << endl;
		r += c[a[i]]++;
	}

	return 0;
}
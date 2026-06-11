#include <iostream>
using namespace std;
int main()
{
	int i;
	int A[1000];
	int N;
	int a = 0;


	cin >> N;


	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	

		if (i % 2 != 0 && A[i] % 2 != 0) {
			a++;
		}


	}
	cout << a;













}


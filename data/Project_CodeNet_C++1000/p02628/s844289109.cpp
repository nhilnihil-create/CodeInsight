#include <iostream>
#include <string>
using namespace std;
int main() {

	int n, k,temp;
	long long d=0;
	cin >> n >> k;

	int* p = new int[n];

	for (int i = 0; i < n; i++) {

		cin >> p[i];
	}
	
	for (int i = 0; i < n; i++) {

		for (int t = i+1; t < n; t++) {

			if (p[i] > p[t])
			{
				temp = p[i];
				p[i] = p[t];
				p[t] = temp;
			}

		}
	}

	for (int i = 0; i < k; i++) {
	 
		d = d + p[i];
	}

	cout << d;


}
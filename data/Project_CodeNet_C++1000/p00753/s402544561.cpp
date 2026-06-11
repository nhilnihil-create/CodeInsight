#include<iostream>
#include<fstream>

using namespace std;

bool isPrime(int n){
	if (n <= 1)return false;
	if (n == 2)return true;
	if (n % 2 == 0)return false;

	for (int i = 3; i * i <= n; i += 2){
		if (n % i == 0)return false;
	}
	return true;
}

int main(){
//	ifstream fin("in.txt");

	int n = 0;
	int count = 0;

	while (true){
		count = 0;

		cin >> n;
		if (n == 0)break;

		for (int i = n + 1; i <= 2 * n; i++)
			if (isPrime(i))count++;

			cout << count << endl;
	}
	return 0;
}
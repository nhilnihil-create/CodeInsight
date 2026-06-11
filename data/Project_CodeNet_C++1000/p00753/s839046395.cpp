#include<iostream>
#include<fstream>

bool isPrime(int n){
	if (n <= 1)return false;
	if (n == 2)return true;
	if (n % 2 == 0)return false;

	for (int i = 3; i * i <= n; i++)
		if (n % i == 0)return false;

	return true;
}

int main(){
	using namespace std;

	//ifstream fin;
	//fin.open("input.txt");

	int n;
	int count;

	while (true){
		n = count = 0;

		cin >> n;
		if (n == 0)break;
		for (int i = n; i <= 2 * n - 1; i+=2){
			if (i == 1 || i == 2)count++;
			if (i % 2 == 0)i++;
			if (isPrime(i))count++;
		}
		if (isPrime(n))count--;
		cout << count << endl;

	}
	return 0;
}
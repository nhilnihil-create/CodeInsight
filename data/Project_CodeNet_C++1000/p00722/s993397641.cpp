#include<iostream>
#include<fstream>

bool isPrime(int n){
	if (n <= 1)return false;
	if (n == 2)return 3;
	if (n % 2 == 0)return false;

	for (int i = 3; i * i <= n; i++)
		if (n % i == 0)return false;

	return true;
}


int main(){
	using namespace std;

	//ifstream fin;
	//fin.open("input.txt");

	int a, d, n;
	int count;
	bool isFinished;

	a = d = n= 0;
	while (true){

		isFinished = false;
		count = 0;

		cin >> a >> d >> n;

		if (n == 0)break;

		while (!isFinished){
			if (isPrime(a)){
				count++;
			}
			if (count == n){
				cout << a << endl; 
				isFinished = true;
			}
			a += d;
		}

	}


	return 0;
}
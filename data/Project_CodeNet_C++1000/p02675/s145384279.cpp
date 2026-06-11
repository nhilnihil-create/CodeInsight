#include <bits/stdc++.h>

using namespace std;

int main()
{
 	int num;
 	cin >> num;
	if(num % 10 == 2 || num % 10 ==  4 ||num % 10 ==  7 || num % 10 == 9 || num % 10 == 5){
		cout << "hon" << endl;
	} else if (num % 10 == 0 ||num % 10 == 1 ||num % 10 == 6 ||num % 10 == 8){
		cout << "pon" << endl;
	} else if (num % 10 == 3){
		cout << "bon" << endl;
	}
}

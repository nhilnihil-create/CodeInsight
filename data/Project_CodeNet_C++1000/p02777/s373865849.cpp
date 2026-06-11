#include<iostream>
#include<string>
#include<vector>
#include<math.h>
#define ll long long
using namespace std;
struct dog {
	string a;
	int b;
};
int main()
{
	dog shiba; dog pa;
	cin >> shiba.a >> pa.a;
	cin >> shiba.b >> pa.b;
	string key;
	cin >> key;
	if (shiba.a == key)shiba.b -= 1;
	else if (pa.a == key)pa.b -= 1;
	cout << shiba.b << " " << pa.b;

}


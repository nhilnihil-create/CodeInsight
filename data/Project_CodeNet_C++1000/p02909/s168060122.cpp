#include<iostream>
using namespace std;
int main()
{
	string a[3] = {"Sunny", "Cloudy", "Rainy"};
	string s;
	cin >> s;
	for(int i = 0; i < 3; ++i) {
		if(a[i] == s) {
			cout << a[(i + 1) % 3];
			break;
		}
	}
  
return 0;
}
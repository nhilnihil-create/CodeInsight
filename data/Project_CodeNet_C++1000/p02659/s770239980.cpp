#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
	long long int A;
	long double B;
  	cin >> A >> B;
  	
  	B = round(B * 100.00);
    long long int r = (A * B) / 100;
  	
  	cout << r << '\n';
}
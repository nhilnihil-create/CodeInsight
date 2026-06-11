#include<iostream>
#define ll long long int
#define ld long long double
using namespace std;

int main(){
  	ll a, b;
 	cin >> a >> b;
  	b *= 2;
  	if(b >= a)
      cout << 0;
  	else
      cout << a - b;
  	return 0;
}
#include <iostream>
using namespace std;
int main(void){ 
int x;
cin >> x;
int n = x / 500 * 1000;
int a = ((x % 500) / 5) *5;
cout << n + a << endl;
}

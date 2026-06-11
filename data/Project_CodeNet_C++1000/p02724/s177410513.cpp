#include <iostream>
using namespace std;
int main(void){ 
int X;
cin >> X;
int N = X / 500 * 1000;
int B = ((X % 500) / 5) *5;
cout << N + B << endl;
}
#include <iostream>
using namespace std;
int main(void){

int a, b, s;

cin >> s;

a = s / 500;

b = s % 500 / 5;

a = a * 1000;

b = b * 5;

int ans = a + b;
 
 cout << ans << endl;   
}

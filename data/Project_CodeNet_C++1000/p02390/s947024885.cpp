#include<iostream>
using namespace std;

int main() {
int w,x,y,z;
cin >> w;
x = w / 3600;
y = (w % 3600)/60;
z = (w % 3600) % 60;
cout << x << ":" << y << ":" << z << endl;
}
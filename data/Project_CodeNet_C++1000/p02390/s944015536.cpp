#include<bits/stdc++.h>
using namespace std;
int main(){
 int a, b, c;
 cin >> a;
 b = a / 3600;
 a -= b * 3600;
 c = a / 60;
 a -= c * 60;
 cout << b << ":" << c << ":" << a << endl;
}


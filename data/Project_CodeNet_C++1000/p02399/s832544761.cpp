#include<iostream>
using namespace std;
int main(){
     int a,b;

     cin >> a >> b;
     cout << a/b << " ";
     cout << a%b << " ";

     double a1,b1;
     a1 = static_cast<double>(a);
     b1 = static_cast<double>(b);
     cout << fixed << a1/b1 << endl;

     return 0;
}
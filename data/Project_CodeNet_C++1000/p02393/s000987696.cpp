#include<iostream>

using namespace std;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  if( a < b && a < c && b <= c ){
    cout << a << " " << b << " " << c << endl;
  } else if( b <= a && b <= c && a <= c ){
    cout << b << " " << a << " " << c << endl;
  } else if( c <= b && c <= a && b <= a ){
    cout << c << " " << b << " " << a << endl;
  } else if( a <= c && a <= b && c <= b ){
    cout << a << " " << c << " " << b << endl;
  } else if( b <= c && b <= a && c <= a ){
    cout << b << " " << c << " " << a << endl;
  } else if( c <= b && b <= a && b <= a  ){
    cout << c << " " << b << " " << a << endl;
  } 

    return 0;
}


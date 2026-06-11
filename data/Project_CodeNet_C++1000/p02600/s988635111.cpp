#include <bits/stdc++.h>
using namespace std;

int main(){
	int X;
	cin >> X;

    if( X <= 599 ) cout << "8" << endl;
    if( (600 <= X) && (X <= 799) ) cout << "7" << endl;
    if( (800 <= X) && (X <= 999) ) cout << "6" << endl;
    if( (1000 <= X) && (X <= 1199) ) cout << "5" << endl;
    if( (1200 <= X) && (X <= 1399) ) cout << "4" << endl;
    if( (1400 <= X) && (X <= 1599) ) cout << "3" << endl;
    if( (1600 <= X) && (X <= 1799) ) cout << "2" << endl;
    if( (1800 <= X) && (X <= 1999) ) cout << "1" << endl;
}

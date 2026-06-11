#include <iostream>
using namespace std;

int main() {
    int X , Y , Z , T;
    cin >> X >> Y >> Z; //1 ≤ X,Y,Z ≤ 100
    T = X ;
    X = Y ;
    Y = T ; 
    T = X ;
    X = Z ;
    Z = T ;
    cout << X << " " << Y << " " << Z << endl;
	return 0;
}
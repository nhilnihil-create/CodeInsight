#include <iostream>
using namespace std;

int main() {
    int A , B , C ; 
    int X , Y , Z ;
    cin >> A >> B >> C ; // 1 ≤ B ≤ A ≤ 20 , 1 ≤ C ≤ 20
    X= A - B;
    Y = min (C, X);
    Z = C - Y;
    cout << Z << endl;
	return 0;
}
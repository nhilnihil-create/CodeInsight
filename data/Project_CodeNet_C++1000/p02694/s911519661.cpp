#include <iostream>
using namespace std;

int main() {
    long long int X,P,a;
    cin >> X;
    P = 100;
    a = 0;
    do{
        P += P/100;
        a++;
    } while (P < X);
    cout << a;

	return 0;
}
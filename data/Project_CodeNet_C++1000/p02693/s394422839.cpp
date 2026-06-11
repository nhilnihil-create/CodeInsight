#include <iostream>

using namespace std;

int main(){
    int A, B, K;
    cin >> K >> A >> B;
    if ((B % K == 0) || (A % K == 0) || (B / K > (A / K))) cout << "OK" << endl;
    else cout << "NG" << endl;
}
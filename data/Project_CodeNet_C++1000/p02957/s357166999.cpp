#include <iostream>
using namespace std;

int main() {
    long long int A , B;
    cin >> A >> B ; // 0 ≤ A,B ≤ 10^9
    if(A % 2 != B % 2) cout << "IMPOSSIBLE"<< endl;
    else cout << (A + B)/2 << endl;
	return 0;
}
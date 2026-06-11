#include <iostream>
using namespace std;

int main() {
    int A , B ;
    cin >> A >> B ; // 1 ≤ A,B ≤ 100
    if (B*2 < A) cout << A - 2*B << endl ;
    if (B*2 >= A) cout << "0" << endl ;
	return 0;
}
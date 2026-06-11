#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int P, Q , R , A ;
    cin >> P >> Q >> R ; // 1 ≤ P,Q,R ≤ 100
    A = P + Q + R - max({P,Q,R});
    cout << A; 
	return 0;
}
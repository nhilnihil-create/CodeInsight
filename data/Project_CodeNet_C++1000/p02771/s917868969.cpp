#include <iostream>
using namespace std;

int main() {
    int A , B , C ;
    cin >> A >> B >> C ; //A , B, and C are all integers between 1 and 9 (inclusive).
    if (A == B && A != C && B != C) cout << "Yes" <<endl;
    if (A == C && A != B && C != B) cout << "Yes" <<endl;
    if (B == C && B != A && C != A) cout << "Yes" <<endl;
    if (B == C && B == A && C == A) cout << "No" <<endl;
    if (B != C && B != A && C != A) cout << "No" <<endl;
	return 0;
}
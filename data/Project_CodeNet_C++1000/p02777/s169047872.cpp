#include <iostream>
#include <string>
using namespace std;

int main() {
    /* S, T, and U are strings of lengths between 1 and 10 (inclusive) consisting of lowercase English letters.
    S≠T
    S=U or T=U.
    1 ≤ A,B≤ 10 */
   
    string  S, T, U ;
    cin >> S >> T ; // 1 ≤ H,A ≤ 10^4
    int A , B ;
    cin >> A >> B ;
    cin >> U ;
    if (U == S) A-- ;
    if (U == T) B-- ;
    cout << A << " " << B << endl ;
	return 0;
}
#include <iostream>
using namespace std;
int main() {
    string S,T;
    int N,syutsuryoku;
    cin >> S;
    cin >> T;
    N = S.size();
    for (int i=0;i<(N-1);i++) {
    if (S.at(i) != T.at(i)) {
        syutsuryoku++;
    }
    }
    if (syutsuryoku != 0) cout << syutsuryoku+1 << endl;
    else cout << syutsuryoku << endl;
    
}

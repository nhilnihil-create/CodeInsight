#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    string S; cin >> S;
    bool T = true;
    for (int i = 0; i < S.length(); ++i) {
        if ((i + 1) % 2 == 0) {
            if (S[i] == 'L' || S[i] == 'U' || S[i] == 'D') continue;
            else {
                T = false;
                break;
            }
        }
        else {
            if (S[i] == 'R' || S[i] == 'U' || S[i] == 'D') continue;
            else {
                T = false;
                break;
            }
        }
    }
    if (T) printf("%s\n", "Yes");
    else printf("%s\n", "No");
}

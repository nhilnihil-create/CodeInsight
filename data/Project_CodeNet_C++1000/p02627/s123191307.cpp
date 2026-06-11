#include <bits/stdc++.h>          
using namespace std;               

int main() {
    char alpha;
    cin >> alpha;
    vector<char> A = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    char ans = 'a';
    for (int i=0; i<26; i++) {
        if (alpha == A[i]) {
            ans = 'A';
            break;
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;




























int main () {
    int K;
    cin >> K;
    
    int result = -1;
    int i = 0;
    int j = 7 % K;
    while (j != 0 && i <= K) {
        j = (j * 10 + 7) % K;
        i++;
    }

    if (i != K + 1) {
        result = i + 1;
    }

    cout << result << endl;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int tmp = n / 1.08;
    int r = 0;
    for (int i = tmp-1; i <= tmp+1; i++) {
        int j = i * 1.08;
        if (j == n) r = i;
    }

    if (r == 0) {
        cout << ":(" << endl;
    } else {
        cout << r << endl;
    }

    return 0;
}

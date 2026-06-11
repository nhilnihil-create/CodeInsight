
#include <bits/stdc++.h>
using namespace std;
int square[100];

int main() {
    int n, sol{ 0 };
    cin >> n;
    for (int i{ 1 }; i <= n; i++) {
        cin >> square[i];
    }

    for (int i{ 1 }; i <= n; i++) {
        if (i % 2 != 0 && square[i] % 2 != 0)sol++;
    }

    cout << sol;
    
    return 0;
}
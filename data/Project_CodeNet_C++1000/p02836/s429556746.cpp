#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int hugs = 0;

    int l = n / 2;
    for (int i = 0; i < l; i++) {
        if (s[i] != s[n - i - 1]) {
            hugs++;
        }
    }
    
    
    cout << hugs;
    return 0;
}

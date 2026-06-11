#include<bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    for(int i = 0; i <= 100; ++i) {
        if(a * i - i + 1 >= b) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}
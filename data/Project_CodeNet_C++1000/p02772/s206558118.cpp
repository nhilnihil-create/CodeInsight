#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    bool jud = true;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 2 == 0) {
            if (a % 3 != 0 && a % 5 != 0) {
                jud = false;
                break;
            }
        }
    }
    cout << (jud ? "APPROVED" : "DENIED") << endl;
}

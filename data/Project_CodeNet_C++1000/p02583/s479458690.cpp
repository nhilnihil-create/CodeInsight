#include <bits/stdc++.h>
using namespace std;

bool isTriangle(int a, int b, int c) {
    if((a + b) <= c) {
        return false;
    }
    if((b + c) <= a) {
        return false;
    }
    if((a + c) <= b) {
        return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> L(n+1);

    for(int i = 1; i <= n; i++) {
        cin >> L[i];
    }

    int ret = 0;
    for(int i = 1; i <= (n - 2); i++) {
        for(int j = i+1; j <= (n - 1); j++) {
            for(int k = j+1; k <= n; k++) { 
                //cout << L[i] << L[j] << L[k] << endl;
                if(L[i] == L[j]) {
                    continue;
                }
                if(L[i] == L[k]) {
                    continue;
                }
                if(L[j] == L[k]) {
                    continue;
                }
                if(isTriangle(L[i], L[j], L[k])) {
                    ret++;
                }
            }
        }
    }
    cout << ret << endl;
}
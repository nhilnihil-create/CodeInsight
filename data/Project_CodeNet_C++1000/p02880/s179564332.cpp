#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int n; cin >> n;
    for(int i=1; i<=9; i++){
        for(int j=1; j<=9; j++){
            if(i*j == n){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
#include <bits/stdc++.h>          
using namespace std;               
typedef long long ll;

int main() {
    ll X;
    cin >> X;
    for(int i=-600; i<601; i++) {
        for (int j=-600; j<601; j++) {
            if (pow(i,5)-pow(j,5) == X) {
                cout << i << " " << j << endl;
                exit(0);
            }
        }
    }
}
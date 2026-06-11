#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int X;
    cin >> X;
    vector<bool> prime(1000001,1);
    prime.at(0) = prime.at(1) = 0;
    for(int i = 2; i < 1000001; i++) {
        if(X <= i && prime.at(i)) {
            cout << i << endl;
            return 0;
        }
        if(prime.at(i)) {
            for(int j = 2; j*i < 1000001; j++) {
                prime.at(j*i) = 0;
            }
        }
    }

    return 0;
}
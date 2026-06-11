#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x;
    cin >> x;
    for(ll i = -200; i < 200; i++) {
        for(ll j = -200; j < 200; j++) {
            if(i*i*i*i*i-j*j*j*j*j==x){
                cout << i << ' ' << j << endl;
                return 0;
            }
        }
    }

}
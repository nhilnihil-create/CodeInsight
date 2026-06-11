#include <bits/stdc++.h>
using namespace std;
int x;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> x;
    for(int i = 1;i <= 1000000;i++) {
        if(i*x%360 == 0) {
            cout << i;
            return 0;
        }
    }
}
#include <bits/stdc++.h>

using namespace std;

long long cost(vector<int> X, int p) {
    long long ans = 0;
    for (auto x : X) {
        ans += (x - p) * (x - p);
    }
    return ans;
}

int main() {
    long long X;
    cin >> X;
    for(int i = 1 ; i <= 50000 ; i++){
        if( i * 108 / 100 == X ){
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
}
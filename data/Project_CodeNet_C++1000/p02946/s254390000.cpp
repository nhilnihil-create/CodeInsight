#include <bits/stdc++.h>
#include <string>
using namespace std;



int main() {
    int k, x; cin >> k >> x;

    for(int i = x - k + 1; i < x; i++){
        cout << i << " ";
    }
    for(int i = x; i < k + x; i++){
        if(k + x == i) cout << i << endl;
        else cout << i << " ";
    }

    return 0;
}


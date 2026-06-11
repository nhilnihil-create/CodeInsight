#include <bits/stdc++.h>
using namespace std;

int main(){

    int k, x;
    cin >> k >> x;

    int l,r;
    l = x - (k - 1);
    r = x + (k - 1);

    for (int i=l; i<=r; i++){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
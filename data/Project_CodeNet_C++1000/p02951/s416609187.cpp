#include <bits/stdc++.h>
using namespace std;

int main(){

    int a, b, c;
    cin >> a >> b >> c;

    int diff;
    diff = a - b;

    if (c - diff > 0){
        cout << c - diff << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}
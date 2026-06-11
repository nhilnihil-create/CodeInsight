#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;

    cin >> a >> b;
    int la = a + '0';
    int lb = b + '0';



    if(lb <= la){
        string s(a, (char)lb);
        cout << s << endl;
    }else {
        string s(b, (char)la);
        cout << s << endl;
    }

    return 0;
}

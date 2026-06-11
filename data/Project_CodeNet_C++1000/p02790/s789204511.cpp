#include <bits/stdc++.h>
using namespace std;

int main () {
    int a, b;
    cin >> a >> b;
    int big=max(a, b);
    int small=min(a, b);
    string mojiretsu=to_string(small);
    if (big>small) {
        for (int i=0; i<big; i++) {
            cout << mojiretsu;
        }
    cout << endl;
    }
    else {
        for (int i=0; i<big; i++) {
            cout << mojiretsu;    
        }
    cout << endl;
    }
}    

    

    

     

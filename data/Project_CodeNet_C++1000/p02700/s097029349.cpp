#include <bits/stdc++.h>          
using namespace std;               

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    
    int takahashi = 0;
    int aoki = 0;
    while (A>0) {
        A-=D;
        takahashi++;
    }
    while (C>0) {
        C-=B;
        aoki++;
    }

    if (takahashi>=aoki) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
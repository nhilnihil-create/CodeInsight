#include <bits/stdc++.h>
using namespace std;


int main () {

    long long  a,b,c;
    cin >> a >> b >> c;
    long long A = 4 * a * b;
    long long B = (c - a - b) *(c -a - b) ;
    if ((c - a - b) < 0){
        cout << "No" <<endl;
        return 0;
    }
    if(A < B){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}



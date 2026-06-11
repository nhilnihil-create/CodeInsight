#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
    string S,T;
    cin >> S >> T;
    int A,B;
    cin >> A >> B;
    string U;
    cin >> U;
    
    if(U==S) {
        A--;
    }else{
        B--;
    }

    cout << A << ' ' << B << endl;
}

#include<bits/stdc++.h>
using namespace std;



int main(void) {
    string S;
    cin >> S;

    if ((S[2] != S[3]) || (S[4] != S[5])) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
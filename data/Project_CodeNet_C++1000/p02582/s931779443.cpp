#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    if('R' == S.at(0) && 'R' == S.at(1) && 'R' == S.at(2)) cout << 3 << endl;
    else if('R' != S.at(0) && 'R' != S.at(1) && 'R' != S.at(2)) cout << 0 << endl;
    else if('S' == S.at(1) || ('S' == S.at(0) && 'R' == S.at(1) && 'S' == S.at(2))) cout << 1 << endl;
    else cout << 2 << endl;
}


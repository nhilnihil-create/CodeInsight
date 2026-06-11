#include <bits/stdc++.h>
using namespace std;

int main(){
    string S,T;
    cin >> S >> T;

    S.swap(T);

    cout << S + T << endl;
} 
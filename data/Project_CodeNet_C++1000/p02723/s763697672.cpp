#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
long long int N, M, Q;
long long int ans = 0;
string S;
vector<long long int>a, b, c, d;
 
 
 
int main() {
    cin >> S;
    if (S[2]==S[3]&&S[4]==S[5]) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i< (n); i++)
using namespace std;
using ll = long long;

int main(void) {
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    string C; cin >> C;
    int pos = alpha.find(C);
    cout << alpha[pos + 1] << endl; 
}
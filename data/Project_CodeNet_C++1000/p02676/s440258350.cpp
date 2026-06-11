#include <bits/stdc++.h>
using namespace std;

int main() {
    int K; string S;
    cin >> K; cin >> S;
    if(K>=S.size()) cout << S << endl;
    else{
        S=S.substr(0,K);
        S=S+"...";
        cout << S << endl;
    }
}

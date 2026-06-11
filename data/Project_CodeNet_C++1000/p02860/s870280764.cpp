#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string S;
    cin >> N;
    cin >> S;
    bool echo = true;

    if (N % 2 != 0) cout << "No" << endl;
    else {
        for (int i = 0; i < (N / 2); i++){
            if(S.at(i) != S.at((N / 2) + i)) echo = false;
        }
    if (!echo)cout << "No" << endl;
    else cout << "Yes" << endl;
    }
}
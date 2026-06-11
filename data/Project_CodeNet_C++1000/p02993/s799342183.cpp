#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string S;
    string output = "Good\n";

    cin >> S;
    for(int i=1;i<S.size();i++) {
        if(S[i-1] == S[i]) output = "Bad\n";
    }

    cout << output ;
    return 0;
}

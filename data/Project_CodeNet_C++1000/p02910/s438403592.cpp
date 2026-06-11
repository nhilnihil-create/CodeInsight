#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    bool ok = true;
    for(int i = 1; i <= S.size(); i++) {
        if(i%2 == 0 && S[i-1] == 'R') {
            ok = false;
            break;
        }
        else if(i%2 == 1 && S[i-1] == 'L') {
            ok = false;
            break;
        }
    }
    if(ok) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}


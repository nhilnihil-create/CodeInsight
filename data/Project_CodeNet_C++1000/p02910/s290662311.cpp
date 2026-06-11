#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string S;
    string output = "Yes\n";

    cin >> S;
    for(int i=0;i<S.size();i++) {
        if(((i%2)==0) && (S[i] == 'L')) {
            output = "No\n";
            break;
        } 
        if((i%2) && (S[i] == 'R')) {
            output = "No\n";
            break;
        }
    }

    cout << output ;
    return 0;
}

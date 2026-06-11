#include <bits/stdc++.h>
using namespace std;
 
int main() {
    string S;
    string T;
    int Q;
    cin >> S >> Q;
    int Quer;
    int F;
    char C;
    int judge = 0;

    for (int i = 0; i < Q; i++) {
        cin >> Quer;
        if (Quer == 1){
            judge++;
        }
        else {
            cin >> F >> C;
            if (F == 1){
                if (judge % 2 == 0){
                    T = T + C;
                }
                else {
                    S = S + C;
                }
            }
            else {
                if (judge % 2 == 0){
                    S = S + C;
                }
                else {
                    T = T + C;
                }
            }
        }
    }
    reverse(T.begin(), T.end());
    S = T + S;
    if (judge % 2 == 1){
        reverse(S.begin(), S.end());
    }
    cout << S << endl;
}

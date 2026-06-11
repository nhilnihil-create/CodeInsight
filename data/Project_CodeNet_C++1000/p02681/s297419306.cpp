#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
int main(void){
    string S,T;
    cin >> S >> T;
    int Slen,Tlen;
    Slen = S.length();
    Tlen = T.length();
    if(Tlen-Slen == 1){
        for(int i=0;i<Slen;i++){
            if(S[i] != T[i]){
                goto error;
            }
        }
        cout << "Yes" << endl;
        return 0;
    }
error:
    cout << "No" << endl;
}

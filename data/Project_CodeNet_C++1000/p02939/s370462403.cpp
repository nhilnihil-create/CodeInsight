#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;

int main(){
    string S;
    cin >> S;

    int L = S.size();
    
    char last = '0';
    int i = 0, K = 0;
    for(int i = 0; i < L; i++){
        char s = S[i];
        if(last == s && i < L-1) {
            s = '0';
            i++;
        }
        if(last != s) K++;
        last = s;
    }

    cout << K << endl;
}
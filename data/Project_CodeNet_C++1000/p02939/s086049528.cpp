#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;

int main(){
    string S;
    cin >> S;

    int L = S.size();
    string last = "";
    int i = 0, K = 0;
    for(int i = 0; i < L; i++){
        string s = S.substr(i, 1);
        if(last == s && i < L-1) {
            s = S.substr(i, 2);
            i++;
        }
        if(last != s) K++;
        last = s;
    }

    cout << K << endl;
}
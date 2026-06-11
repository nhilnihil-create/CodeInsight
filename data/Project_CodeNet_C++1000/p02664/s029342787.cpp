#include <bits/stdc++.h>
using namespace std;

int main(){
    string S; cin >> S;
    int n = S.size();
    for (int i= 0; i <n ; i++){
        if (S[i] == '?'){
            S[i] = 'D';
        }
    }
    cout << S << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
    string S, T;
    cin >> S >> T;
    if(S.size() + 1  != T.size()){
        cout << "No" << endl;
        return 0;
    }
    T.erase(T.size()-1);
    if(S == T) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
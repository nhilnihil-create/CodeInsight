#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(){
    string s;
    cin >> s;
    char before = 'i';
    if(s.size() == 1){
        cout << "No" << endl;
        return 0;
    }
    rep(i,s.size()){
        if(before == 'i' && s.at(i)== 'h')before = 'h';
        else if(before == 'h' && s.at(i) == 'i')before = 'i';
        else {
            cout << "No" << endl;
            return 0;
        }
    }
    if(before == 'i')cout << "Yes" << endl;
    else cout << "No" << endl;
}
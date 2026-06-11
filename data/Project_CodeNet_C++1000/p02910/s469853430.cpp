#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    for (int i = 1; i < s.size()+1; i++){
        if(i == 1){
            if(s.at(i-1) == 'L'){
                cout << "No" << endl;
                return 0;
            }
        }else if(i % 2 == 0){
            if(s.at(i-1) == 'R'){
                cout << "No" << endl;
                return 0;
            }
        }else{
            if(s.at(i-1) == 'L'){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}
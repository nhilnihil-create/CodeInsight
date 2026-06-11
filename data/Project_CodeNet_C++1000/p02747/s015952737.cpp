#include<bits//stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;
    if(s.length() % 2 == 1){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < s.length(); i += 2){
        if(s[i] != 'h'){
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = 1; i < s.length(); i += 2){
        if(s[i] != 'i'){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
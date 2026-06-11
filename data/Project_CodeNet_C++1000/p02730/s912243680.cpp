#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    for(int i = 0; i < (s.size()-1)/4; i++){
        if(s[i] != s[(s.size()-1)/2 - 1 - i]){
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = (s.size()+3)/2 - 1; i < (s.size()+3)/2 + (s.size()-1)/4; i++){
        if(s[i] != s[s.size() - i - 2 + (s.size()+3)/2]){
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i = 0; i < s.size()/2; i++){
        if(s[i] != s[s.size()-i-1]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
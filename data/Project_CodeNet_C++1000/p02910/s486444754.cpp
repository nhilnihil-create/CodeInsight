#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin >> s;
    bool flag = true;
    for(int i = 0; i < s.size(); i += 2){
        if(s.at(i) == 'R' || s.at(i) == 'U' || s.at(i) == 'D'){
            
        }else{
            flag = false;
        }
    }
    for(int i = 1; i < s.size(); i += 2){
        if(s.at(i) == 'L' || s.at(i) == 'U' || s.at(i) == 'D'){
            
        }else{
            flag = false;
        }
    }
    if(flag == true){
        cout << "Yes";
    }else{
        cout << "No";
    }
}
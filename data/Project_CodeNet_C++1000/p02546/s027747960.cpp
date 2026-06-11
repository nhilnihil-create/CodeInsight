#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    
    string s;
    cin >> s;
    int n = s.length();
    for(int i=0; i<n; i++){
        if(i == n-1){
            if(s[i] == 's'){
                cout << s[i] << "es";
            }
            else{
                cout << s[i] << "s";
            }
        }
        else cout << s[i];
    }
    return 0;
}
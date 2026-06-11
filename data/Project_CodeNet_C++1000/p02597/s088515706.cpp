#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'R'){
            r++;
        }
    }
    int cnt = 0;
    for(int i = 0; i < r; i++){
        if(s[i] == 'W'){
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
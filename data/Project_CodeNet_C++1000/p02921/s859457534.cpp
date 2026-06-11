#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(void){
    string s,t;
    cin >> s >> t;
    int count = 0;
    rep(i,3){
        if(s[i]==t[i]){
             count++;
        }
        
    }

    cout << count << endl;
}
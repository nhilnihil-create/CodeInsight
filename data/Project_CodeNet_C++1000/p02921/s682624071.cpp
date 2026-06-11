//
// Created by karth on 4/28/2020.
//
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
typedef long long ll;


int main(){
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for(int i = 0; i < s.length(); ++i){
        if(s[i] == t[i]){
            ans++;
        }
    }
    cout << ans << "\n";
}



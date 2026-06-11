#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep1(i,n) for(int i = 1; i < (n); i++)

int main(){
    string s;
    cin >> s;
    bool ok = true;
    rep(i,s.length()){
        if(i%2==0 && s[i] == 'L') ok = false;
        if(i%2==1 && s[i] == 'R') ok = false;
    }
    if(ok) cout << "Yes" << endl;
    if(!ok) cout << "No" << endl;
}
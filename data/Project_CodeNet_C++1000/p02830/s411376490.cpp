#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rep1(i,n) for(int i = 1; i < (n); i++)

int main(){
    int n;
    cin >> n;
    char s[n];
    char t[n];
    rep(i,n){
        cin >> s[i];
    }
    rep(i,n){
        cin >> t[i];
    }
    rep(i,n){
        cout << s[i] << t[i];
    }
    cout << endl;
}
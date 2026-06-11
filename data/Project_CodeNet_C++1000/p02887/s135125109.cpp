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
    string s;
    cin >> n >> s;
    int ans = n;
    rep1(i,n) if(s[i] == s[i-1]) ans--;
    cout << ans << endl;
}
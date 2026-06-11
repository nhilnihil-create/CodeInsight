#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    rep(i,n){
        if(s[i]==s[n-1-i]){
            continue;
        }
        else{
            cout << "No";
            return 0;
        }
    }
    string a = s.substr(0,(n-1)/2);
    string b = s.substr((n-1)/2+1,(n-1)/2);
    rep(i,a.size()){
        if(a[i]!=a[a.size()-1-i]){
            cout << "No";
            return 0;
        }
        if(b[i]!=b[b.size()-1-i]){
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";

    return 0;
}
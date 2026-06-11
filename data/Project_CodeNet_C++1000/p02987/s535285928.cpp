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
    cin >>s;
    sort(s.begin(),s.end());
    rep(i,2){
        if(s[2*i]==s[2*i+1]){
            continue;
        }
        else{
            cout << "No";
            return 0;
        }
    }
    if(s[1]==s[2]){
        cout << "No";
    }
    else{
        cout << "Yes";
    }

    return 0;
}
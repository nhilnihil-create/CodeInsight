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
    int a,b,c;
    cin >> a >> b >> c;
    if(a==b){
        if(b!=c){
            cout << "Yes";
            return 0;
        }
    }
    else if(a==c){
        if(c!=b){
            cout << "Yes";
            return 0;
        }
    }
    else if(b == c){
        if(c!=a){
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";

    return 0;
}
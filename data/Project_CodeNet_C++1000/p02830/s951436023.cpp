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
    int n;
    cin >> n;
    string s,d;
    cin >> s >> d;
    rep(i,2*n){
        if(i%2==0){
            cout << s[i/2];
        }
        else{
            cout << d[(i-1)/2];
        }
    }

    return 0;
}
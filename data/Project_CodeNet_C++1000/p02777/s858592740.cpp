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
    string s,t;
    int a,b;
    string u;
    cin >> s >> t >> a >> b >> u;
    if(u==s){
        a--;
    }
    else{
        b--;
    }
    cout << a << " " << b;
    return 0;
}
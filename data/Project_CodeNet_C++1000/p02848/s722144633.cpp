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
    string s;
    cin >> n >> s;
    int a = 'A' - 0;
    rep(i,s.size()){
        int m = s[i] -0;
        int e = (m-a+n)%26;
        char p = e+a;
        cout << p;
    }

    return 0;
}
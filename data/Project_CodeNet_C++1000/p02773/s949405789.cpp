#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <map>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


using namespace std;

bool is_integer( float x ){
    return floor(x)==x;
}


int main() {
    string s[200000];
    map<string,int> mp;
    int n; cin >> n;
    int Max = -1;
    rep(i,n)cin >> s[i];
    sort(s,s+n);
    rep(i,n) mp[s[i]] = 0;
    rep(i,n){
        mp[s[i]] ++;
        Max = max(Max,mp[s[i]]);
    }
    rep(i,n){
        if(mp[s[i]] == Max){
            mp[s[i]] = -1;
            cout << s[i] << endl;
        }
    }
    return 0;
}










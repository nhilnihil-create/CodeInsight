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
#include <queue>


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)


using namespace std;

bool is_integer( float x ){
    return floor(x)==x;
}


int main() {
    string s;
    cin >> s;
    int ans = 0;
    int n = s.length();
    string prev,cur;

    rep(i,n){
        if(i == 0){
            prev = s[0];
            ans ++;
        }else{
            cur += s[i];
            if(cur != prev){
                prev = cur;
                cur = "";
                ans ++;
            }
        }
    }

    cout << ans;
    return 0;
}










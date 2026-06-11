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

#define FOR(i,l,r) for(size_t i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)



using namespace std;

bool is_integer( float x ){
    return floor(x)==x;
}


int main() {

    int n;
    int a[200000];
    int count = 0;
    int cur = 1;
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> a[i];
    }

    for(int i = 0; i < n; i ++){
        if(a[i] == cur){
            cur ++;
        }else{
            count ++;
        }
    }
    if(count == n) cout << -1;
    else cout << count;
    return 0;
}










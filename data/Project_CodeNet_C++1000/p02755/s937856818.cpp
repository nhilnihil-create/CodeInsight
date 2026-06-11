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
    int a,b;
    int flag = false;
    vector<int> vc;
    cin >> a >> b;

    for(int i = a; i < 10000; i ++){
        if((int)(i*0.08) == a) vc.push_back(i);
    }

    for(int i = 0; i < vc.size(); i ++){
        if((int)(vc[i]*0.1) == b){
               cout << vc[i];
               flag = true;
               break;
        }
    }

    if(!flag) cout << -1;

    return 0;
}










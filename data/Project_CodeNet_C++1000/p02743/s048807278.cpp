#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    LL a, b, c;
    cin >> a >> b >> c;

    if( 4*a*b < (c-a-b)*(c-a-b) && 0 < c-a-b){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
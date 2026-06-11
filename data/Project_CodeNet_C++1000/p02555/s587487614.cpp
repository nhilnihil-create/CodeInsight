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

LL p = 1E9+7;

int main(){
    int S;
    cin >> S;

    vector<LL> ans(S+1, 0);
    
    REP(i, S+1){
        if(i==0){ans[0] = 1; continue;}
        if(i<=2){ans[i] = 0; continue;}

        ans[i] = (ans[i-3] + ans[i-1])%p;
    }

    cout << ans[S] << endl;
    return 0;
}
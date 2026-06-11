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
    int N;
    cin >> N;
    vector<LL> a(N, 0);
    REP(i,N){cin >> a[i];}

    LL a_all = a[0];
    FOR(i,1,N){
        a_all ^= a[i];
    }

    REP(i,N){
        LL ans = a_all ^ a[i];
        cout << ans << " ";  
    }

    return 0;
}
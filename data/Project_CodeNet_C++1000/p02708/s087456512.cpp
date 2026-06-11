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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

LL p = 1E9+7;

int main(){
    int N, K;
    cin >> N >> K;

    vector<LL> count(N+2, 0);
    
    LL min_range = 0;
    LL max_range = 0;
    FOR(i, 1, N+2){
        min_range += i - 1;
        max_range += N - (i - 1);

        count[i] = max_range - min_range + 1;
    }

    LL ans = 0;
    FOR(i, K, N+2){
        ans = (ans + count[i])%p;
    }
    
    cout << ans << endl;
    return 0;
}
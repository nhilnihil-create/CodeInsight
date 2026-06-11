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

int main(){
    LL L, R;
    cin >> L >> R;

    if(R >= L+2019){
        cout << 0 << endl;
        return 0;
    }

    priority_queue<LL, vector<LL>, greater<LL>> que;
    for(LL i=L; i<=R; i++){
        for(LL j=i+1; j<=R; j++){
            LL r1 = i%2019;
            LL r2 = j%2019;
            que.push((r1*r2)%2019);
        }
    }

    LL ans = que.top();
    cout << ans << endl;
    return 0;


}
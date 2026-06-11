#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    ll K,tmp = 0;
    cin >> K;
    queue<ll> R;
    REP(i,9)R.push(i+1);

    FOR(i,0,K){
        tmp = R.front();
        if(tmp % 10 != 0){
            R.push(10*tmp + (tmp%10) - 1);
        }
        R.push(10*tmp + (tmp%10));
        if(tmp % 10 != 9){
            R.push(10*tmp + (tmp%10) + 1);
        }
        R.pop();
    }
    cout << tmp << endl;
    return 0;
}
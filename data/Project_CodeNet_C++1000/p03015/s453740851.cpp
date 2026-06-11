#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<iomanip>

#define REP(i,n) for(int i=0;i<(n);i++)
#define EPS (1e-7)
#define INF (2e9)
// cout << setprecision(10)

using namespace std;
typedef long long int ll;
const int MOD =1000000007;

string s;
int main(void){
    cin >> s;
    ll top = 1;
    ll below = 0;
    REP(i, s.length()){
        if(s[i] == '1'){
            below = (3*below + top) % MOD;
            top = (2*top) % MOD;
        }else{
            below = (3*below) % MOD;
        }
    }

    cout << (top + below) % MOD << endl;
    return 0;
}


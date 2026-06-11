#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)
const int MOD = 1000000007;

int main(void){
    string S;
    cin >> S;
    if(S[2] == S[3] && S[4] == S[5]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
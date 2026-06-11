#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    int N,M,sum=0;
    cin >> N >> M;
    vector<int> A(M+10);
    REP(i,M){
        int A;
        cin >> A;
        sum += A;
    }
    if(N-sum < 0) cout << "-1" << endl;
    else cout << N - sum << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    int N;
    cin >> N;
    vector<int> A(N);
    A[0] = 0;
    FOR(i,1,N){
        int tmp;
        cin >> tmp;
        tmp--;
        A[tmp]++;
    }
    REP(i,N) cout << A[i] << endl;
    return 0;
}
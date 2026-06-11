#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define EFOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REP(i, n) FOR(i,0,n)

int main(void){
    double M,N,MVote=0,tmpm=0;
    cin >> N >> M;
    tmpm = M;
    vector<int> A(1010,0);
    REP(i,N){
        cin >> A[i];
        MVote += A[i];
    }

    FOR(i,0,N){
        if(A[i] >= MVote/(4*tmpm)) M--;
        if(M <= 0){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
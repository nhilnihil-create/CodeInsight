#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef int64_t Int;

Int N, M, V, P;
vector<Int> A(100010);

bool saiyou(int X){ //スコアがX番目の問題が採用されうるか
    if(X <= P-1) return true;
    if(A[X] + M < A[P-1]) return false;

    Int votes = 0;
    rep(i,N){
        if(i<=P-2) votes += M;
        else if(i >= X) votes += M;
        else votes += A[X]+M - A[i];
    }

    return votes >= M*V;
}

int main(){
    cin >> N >> M >> V >> P;
    rep(i,N) cin >> A[i];

    sort(A.begin(), A.begin()+N, greater<Int>());
    
    int l=0, r = N;
    while(r-l>1){
        int mid = (l+r)/2;
        if(saiyou(mid)) l = mid;
        else r = mid;
    }

    cout << r << endl;
}

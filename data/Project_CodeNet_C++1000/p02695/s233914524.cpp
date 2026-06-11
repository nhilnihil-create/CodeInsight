#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)
int N,M,Q,ans=0;
vector<int> a,b,c,d;
vector<int> A(11);
void DFS(int i){
    //A_iが定義されたら，Qについてのループ
    if(i == N){
        int sum = 0;
        REP(j,Q){
            if(A[b[j]] - A[a[j]] == c[j]) sum += d[j];
        }
        ans = max(ans,sum);
        return;
    }
    FOR(j,min(A[i],M),M+1){//for(int j=min(A[i],M);j <=M;j++){
        A[i+1] = j;
        DFS(i+1);
    }
}

int main(void){
    cin >> N >> M >> Q;
    a.resize(Q);
    b.resize(Q);
    c.resize(Q);
    d.resize(Q);
    REP(i,Q) cin >> a[i] >> b[i] >> c[i] >> d[i];
    A[0] = 1;
    DFS(0);
    cout << ans << endl;
    return 0;
}
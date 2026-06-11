#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)

int main (void){
    int N,K;
    cin >> N >> K;
    vector<int> d;
    vector<vector<int>> A;
    d.resize(K);
    A.resize(K, vector<int>());
    REP(i,K){
        cin >> d[i];
        A[i].resize(d[i]);
        REP(j,d[i]){
            cin >> A[i][j];
        }
    }
    int cnt = 0;
    for(int i=1;i<=N;i++){
        bool have = false;
        for(auto v:A){
            for(auto p:v){
                if(p == i) have = true;
            }
        }
        if(!have) cnt++;
    }

    cout << cnt << endl;

}
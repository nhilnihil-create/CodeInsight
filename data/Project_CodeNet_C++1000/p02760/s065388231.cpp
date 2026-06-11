#include <bits/stdc++.h>
using namespace std;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define ll long long
const long long INF = 1LL<<60;
const long long mod = 1e9 + 7;
using Graph = vector<vector<int>>;

int main(){
    int A[3][3];
    bool Bingo = false;
    bool field[3][3];
    REP(i,3){
        REP(j,3) cin >> A[i][j];
    }
    int N;
    cin >> N;
    int b[N];
    REP(i,N) cin >> b[i];
    REP(i,3){
        REP(j,3){
            field[i][j] = false;
            REP(k,N){
                if(b[k] == A[i][j]) field[i][j] = true;
            }
        }
    }

    if(field[0][0]&&field[0][1]&&field[0][2]) Bingo = true;
    if(field[1][0]&&field[1][1]&&field[1][2]) Bingo = true;
    if(field[2][0]&&field[2][1]&&field[2][2]) Bingo = true;
    if(field[0][0]&&field[1][0]&&field[2][0]) Bingo = true;
    if(field[0][1]&&field[1][1]&&field[2][1]) Bingo = true;
    if(field[0][2]&&field[1][2]&&field[2][2]) Bingo = true;
    if(field[0][0]&&field[1][1]&&field[2][2]) Bingo = true;
    if(field[0][2]&&field[1][1]&&field[2][0]) Bingo = true;
    if(Bingo) cout << "Yes" << endl;
    else cout << "No" << endl;
}
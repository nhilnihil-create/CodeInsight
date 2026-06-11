#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N, M, X;
    cin >> N >> M >> X;

    vector<int> C(N);
    vector< vector<int> > A(N, vector<int>(M));
    int i,j;

    for( i = 0; i < N; i++ ){
        cin >> C[i];
        for( j = 0; j < M; j++ ){
            cin >> A[i][j];
        }
    }

    int ibit;
    vector<int>  skill(M);
    int cost;
    int flag;
    int ans = -1;
    for( ibit = 0; ibit < (1<<N); ibit++ ){
        // initialize
        cost = 0;
        flag = 0;
        for( j = 0; j < M; j++ ) skill[j] = 0;

        for( i = 0; i < N; i++ ){
            if( ibit & 1<<i ){
                cost += C[i];
                for( j = 0; j < M; j++ ) skill[j] += A[i][j];
            }
        }
        // check
        for( j = 0; j < M; j++ ){
            if( skill[j] < X ) flag = 1;
        }
        if( flag != 1 ){
            if( ans == -1 || ans > cost ) ans = cost;
        }
    }

    cout << ans << endl;


}

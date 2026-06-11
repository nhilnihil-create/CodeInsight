#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

    int A[3][3];
    bool bingo[3][3];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> A[i][j];
            bingo[i][j] = false;
        }
    }
    int N;
    cin >> N;
    int b[N];
    for(int i = 0; i < N; i++){
        cin >> b[i];
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(A[j][k] == b[i]){
                    bingo[j][k] = true;
                }
            }
        }
    }

    if(bingo[0][0] && bingo[0][1] &&bingo[0][2] ){ cout << "Yes" << endl;}
    else if(bingo[1][0] && bingo[1][1] &&bingo[1][2] ){cout << "Yes" << endl;}
    else if(bingo[2][0] && bingo[2][1] &&bingo[2][2] ){cout << "Yes" << endl;}
    else if(bingo[0][0] && bingo[1][0] &&bingo[2][0] ){cout << "Yes" << endl;}
    else if(bingo[0][1] && bingo[1][1] &&bingo[2][1] ){cout << "Yes" << endl;}
    else if(bingo[0][2] && bingo[1][2] &&bingo[2][2] ){cout << "Yes" << endl;}
    else if(bingo[0][0] && bingo[1][1] &&bingo[2][2] ){cout << "Yes" << endl;}
    else if(bingo[0][2] && bingo[1][1] &&bingo[2][0] ){cout << "Yes" << endl;}
    else {cout << "No" << endl;}

    return 0;
}
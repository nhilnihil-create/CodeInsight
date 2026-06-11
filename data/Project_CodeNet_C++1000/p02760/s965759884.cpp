#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    int A[3][3];
    int B[3][3];
    for(int i=0;i<3;i++){
     for(int j=0;j<3;j++){
         cin >> A[i][j];
         B[i][j] = 0;
     }
    }

    int N;
    cin >> N;
    for(int n=0;n<N;n++){
        int ni;
        cin >> ni;
            for(int i=0;i<3;i++){
             for(int j=0;j<3;j++){
                 if(A[i][j] == ni){
                    B[i][j] = 1;
                 }
             }
            }
    }

    int f_0x = 1;
    int f_1x = 1;
    int f_2x = 1;
    int f_x0 = 1;
    int f_x1 = 1;
    int f_x2 = 1;
    int f_z1 = 1;
    int f_z2 = 1;
    int i;


    for(i=0;i<3;i++){
        f_0x *= B[0][i];
        f_1x *= B[1][i];
        f_2x *= B[2][i];
        f_x0 *= B[i][0];
        f_x1 *= B[i][1];
        f_x2 *= B[i][2];
        f_z1 *= B[i][i];
        f_z2 *= B[2-i][i];
    }
    if(f_0x + f_1x + f_2x + f_x0 + f_x1 + f_x2 + f_z1 + f_z2 == 0){cout << "No" << endl;}
    else{cout << "Yes" << endl;}


    return 0;
}

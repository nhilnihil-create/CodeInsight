#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
int min(int a,int b){
    return a < b ? a : b;
}
int main(void){
    int N,M,X;
    cin >> N >> M >> X;
    int C[N];
    int A[N][M];
    for(int i=0;i<N;i++){
        cin >> C[i];
        for(int j=0;j<M;j++){
            cin >> A[i][j];
        }
    }
    int ans = 1000000000;
    bool ac;
    for(int i=1;i<2<<N-1;i++){
        int sum = 0;
        int skill[12] = {0};
        ac = true;
        for(int j=0;j<N;j++){
            if((i >> j) & 1){
                sum += C[j];
                for(int k=0;k<M;k++){
                    skill[k] += A[j][k];
                }
            }
        }
        for(int j=0;j<M;j++){
            if(skill[j] < X){
                ac = false;
                break;
            }
        }
        if(ac){
            ans = min(ans,sum);
        }
    }
    if(ans == 1000000000)ans = -1;
    cout << ans;
}
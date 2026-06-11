#include <iostream>

using namespace std;

int func(int ans){
    
    if(ans == 1)return 1;
    return ans *= func(ans - 1);
}

void fuck(int X[], int box, int N){
    for(int i = 1; i < N; i ++){
        if(X[i] > box)X[i] --;
        X[i - 1] = X[i];
    }
}

int main(){
    int N, P[10], Q[10], cntP = 0, cntQ = 0;

    cin >> N;
    for(int i = 0; i < N; i ++)cin >> P[i];
    for(int j = 0; j < N; j ++)cin >> Q[j];

    int box;
    while(1){
        if(N == 1)break;
        box = P[0];
        cntP += func(N - 1) * (box - 1);
        fuck(P, box, N);
        box = Q[0];
        cntQ += func(N - 1) * (box - 1);
        fuck(Q, box, N);
        N --;
    }

    cout << abs((cntP + 1) - (cntQ + 1)) << endl;

    return 0;
}
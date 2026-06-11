#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 2005;
int L[MAX_N][MAX_N] = {0};
int R[MAX_N][MAX_N] = {0};
int U[MAX_N][MAX_N] = {0};
int D[MAX_N][MAX_N] = {0};

int main(void){
    int H,W;
    cin >> H >> W;
    vector<string> field(H);
    for(int i=0;i<H;i++) cin >> field[i];

    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            if(field[i][j]=='#') continue;
            if(j==0) L[i][j] = 1;
            else L[i][j] = L[i][j-1] + 1;
        }
    }
    for(int i=0;i<H;i++){
        for(int j=W-1;j>=0;j--){
            if(field[i][j]=='#') continue;
            if(j==W-1) R[i][j] = 1;
            else R[i][j] = R[i][j+1] + 1;
        }
    }
    for(int j=0;j<W;j++){
        for(int i=0;i<H;i++){
            if(field[i][j]=='#') continue;
            if(i==0) U[i][j] = 1;
            else U[i][j] = U[i-1][j] + 1;
        }
    }
    for(int j=0;j<W;j++){
        for(int i=H-1;i>=0;i--){
            if(field[i][j]=='#') continue;
            if(i==H-1) D[i][j] = 1;
            else D[i][j] = D[i+1][j] + 1;
        }
    }

    int maxlight = 0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            int now = L[i][j] + R[i][j] + U[i][j] + D[i][j] -3;
            maxlight = max(maxlight, now);
        }
    }
    cout << maxlight << endl;
}
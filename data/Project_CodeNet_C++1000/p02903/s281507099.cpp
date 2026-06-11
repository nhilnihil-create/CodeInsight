#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MOD = 1e9+7;

int main(){
    int H, W; cin >> H >> W;
    int A, B; cin >> A >> B;
    vector<vector<int>> V(H, vector<int> (W));
    if(A == 0 || B == 0){
        if(A == 0){
            for(int i = 0; i < W; i++){
                for(int j =0 ; j < B; j++) V[j][i] = 1;
            }
        }
        else{
            for(int i = 0; i < H; i++){
                for(int j = 0; j < A; j++) V[i][j] = 1;
            }

        }

    }
    //else if(H *A != W*B) {cout << "No" << endl; return 0;}
    else {
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(i == 0 || j == 0) V[i][j] = 1;
            }
        }
        V[0][0] = 0;
        for(int i = 0; i < A-1; i++){
            for(int j = 0; j < H; j++){
                V[j][W-1-i] = (V[j][W-1-i]+1)%2;
            }
        }

        for(int i = 0; i < B-1; i++){
            for(int j = 0; j < W; j++){
                V[H-1-i][j] = (V[H-1-i][j]+1)%2;
            }
        }
    }
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cout << V[i][j];
    cout << endl;
    }
    //cout << "No" << endl;
}

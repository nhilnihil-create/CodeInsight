#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int H,W;
    cin >> H >> W;
    int A,B;
    cin >> A >> B;
    vector<vector<int> > vec(H, vector<int> (W));
    for (int i = 0; i < B; i++){
        for (int j = 0; j < A; j++){
            vec[i][j] = 1;
        }
        for (int j = A; j < W; j++){
            vec[i][j] = 0;
        }
    }
    for (int i = B; i < H; i++){
        for (int j = 0; j < A; j++){
            vec[i][j] = 0;
        }
        for (int j = A; j < W; j++){
            vec[i][j] = 1;
        }
    }
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            cout << vec[i][j];
        }
        cout << endl;
    }
}
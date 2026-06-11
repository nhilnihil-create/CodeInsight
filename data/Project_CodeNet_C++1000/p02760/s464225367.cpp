#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    string ans = "No";
    vector<vector<int>> A(3, vector<int>(3));
    vector<vector<bool>> C(3, vector<bool>(3, false));
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j) cin >> A[i][j];
    }
    cin >> N;
    vector<int> B(N);
    for(auto& b : B) cin >> b;
    if(N < 3) ans = "No";
    else{
        for(auto b : B){
            for(int i = 0; i < 3; ++i){
                for(int j = 0; j < 3; ++j){
                    if(A[i][j] == b) C[i][j] = true;
                }
            }
        }
        for(int i = 0; i < 3; ++i){
            if(C[i][0] && C[i][1] && C[i][2]) ans = "Yes";
            else if(C[0][i] && C[1][i] && C[2][i]) ans = "Yes";
        }
        if((C[0][0] && C[1][1] && C[2][2]) || (C[0][2] && C[1][1] && C[2][0])) ans = "Yes";
    }
    /*
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            cout << C[i][j] << ",";
        }
        cout << endl;
    }
    */
    cout << ans << endl;
    return 0;
}
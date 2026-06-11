#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, D;
    cin >> N >> D;
    vector<vector<int>> A(N, vector<int>(D));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < D; j++){
            cin >> A.at(i).at(j);
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            int norm = 0;
            for(int k = 0; k < D; k++){
                int dis = abs(A.at(i).at(k) - A.at(j).at(k));
                norm += dis * dis;
            }
            bool add = false;
            for(int l = 0; l <= norm; l++){
                if(l * l == norm){
                    add = true;
                }
            }
            if(add){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
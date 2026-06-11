#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<vector<int>> x(N, vector<int>(N)), y(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        cin >> A[i];
        for(int j = 0; j < A[i]; j++){
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }
    int ans = 0;
    for(int bit = 1; bit < (1 << N); bit++){
        int cnt = 0;
        int flag = 0;
        for(int j = 0; j < N; j++){
            if(bit & (1 << j)){
                for(int k = 0; k < A[j]; k++){
                    if(y[j][k] == 0 && bit & (1 << x[j][k])) {
                        flag = 1;
                        break;
                    }
                    if(y[j][k] == 1 && (bit & (1 << x[j][k])) == 0) {
                        flag = 1;
                        break;
                    }
                }
                cnt++;
            }
            if(flag == 1) break;
        }
        if(flag == 0) ans = max(ans, cnt);
    }
    cout << ans << endl;
}
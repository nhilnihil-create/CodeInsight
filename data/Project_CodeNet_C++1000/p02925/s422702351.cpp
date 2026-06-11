#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<vector<int>> A(N, vector<int>(N - 1));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N - 1; j++) {
            cin >> A[i][j];
            A[i][j]--;
        }
    }
    vector<int> cnt(N, 0);
    int ans = 0;
    time_t s, t;
    time(&s);
    while(1){
        ans++;
        int flag2 = 0;
        time(&t);
        if(t - s > 0){
            cout << N * (N - 1) / 2 << endl;
            return 0;
        } 
        vector<int> used(N, 0);
        for(int i = 0; i < N; i++){
            int ind = A[i][cnt[i]];
            if(used[i] == 1 || used[ind] == 1 || cnt[i] == N - 1) continue;
            if(A[ind][cnt[ind]] == i){
                cnt[i]++;
                cnt[ind]++;
                used[i] = 1;
                used[ind] = 1;
                flag2 = 1;
            }
        }
        if(flag2 == 0){
            cout << -1 << endl;
            return 0;
        }
        int flag = 0;
        for(int i = 0; i < N; i++){
            if(cnt[i] != N - 1) flag = 1;
        }
        if(flag == 0) break;
    }
    cout << ans << endl;
}
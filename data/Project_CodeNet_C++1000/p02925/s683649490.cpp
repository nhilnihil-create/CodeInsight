#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
typedef pair<int, int> P;
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
    queue<P> q;
    vector<int> cnt(N, 0);
    vector<int> used(N, 0);
    auto check = [&](int i){
        if(cnt[i] == N - 1) return;
        int j = A[i][cnt[i]];
        if(cnt[j] == N - 1) return;
        if(A[j][cnt[j]] != i) return;
        if(i > j) swap(i, j);
        used[j] = 1;
        used[i] = 1;
        q.push(P(i, j));
    };
    for(int i = 0; i < N; i++){
        if(used[i] == 1) continue;
        check(i);
    }
    int day = 0;
    while(!q.empty()){
        day++;
        used.assign(N, 0);
        queue<P> que;
        while(!q.empty()){
            P v = q.front();
            que.push(v);
            q.pop();
            int i = v.first, j = v.second;
            cnt[i]++;
            cnt[j]++;
        }
        while(!que.empty()){
            P v = que.front();
            que.pop();
            int i = v.first, j = v.second;
            if(used[i] == 1 && used[j] == 0) {
                check(j);
            }
            else if(used[i] == 0 && used[j] == 1){
                check(i);
            }
            else if(used[i] == 0 && used[j] == 0){
                check(i);
                check(j);
            }
        }
    }
    for(int i = 0; i < N; i++){
        if(cnt[i] != N - 1){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << day << endl;
}

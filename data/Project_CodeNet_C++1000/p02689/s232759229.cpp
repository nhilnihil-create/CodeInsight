#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M, ans = 0, buf1, buf2;
    cin >> N >> M;
    vector<priority_queue<int>> Q(N+1);
    vector<int> H(N+1);
    for(int i = 1; i <= N; ++i)cin >> H[i];
    for(int j = 0; j < M; ++j){
        cin >> buf1 >> buf2;
        Q[buf1].push(H[buf2]);
        Q[buf2].push(H[buf1]);
    }
    for(int i = 1; i <= N; ++i){
        if(Q[i].empty())++ans;
        else if(Q[i].top() < H[i]) ++ans;
    }
    cout << ans << endl;
    return 0;
}
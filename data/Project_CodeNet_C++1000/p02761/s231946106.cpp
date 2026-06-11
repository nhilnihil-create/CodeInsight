#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> ans(N+1, -1);
    int s[10010], c[10010];
    for(int i = 1; i <= M; ++i) cin >> s[i] >> c[i];
    for(int i = 1; i <= M; ++i){
        if( (ans[s[i]] != -1 && ans[s[i]] != c[i]) || (s[i] == 1 && c[i] == 0 && N > 1)){
            cout << -1 << endl;
            return 0;
        }
        else ans[s[i]] = c[i];
    }
    for(int i = 1; i <= N; ++i){
        if(ans[i] == -1){
            if(i == 1 && N > 1) ans[i] = 1;
            else ans[i] = 0;
        }
    }
    for(int i = 1; i <= N; ++i){
        cout << ans[i];
    }
    cout << endl;
    return 0;
}
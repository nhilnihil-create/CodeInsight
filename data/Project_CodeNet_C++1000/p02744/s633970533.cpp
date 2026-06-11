#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N;
void dfs(char c,string S) {
    if(S.size() == N) {
        cout << S << endl;
        return;
    }
    for(char i = 'a'; i <= c; i++) {
        dfs(max((int)c,(int)i+1),S+i);
    }
    return;
}
signed main(){
    cin >> N;
    dfs('a',"");
}

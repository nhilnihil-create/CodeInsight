#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n, k;
    cin >> n >> k;
    if((n-1)*(n-2)/2 < k){
        cout << -1 << endl;
        return 0;
    }
    vector<vector<int>> node(n+1, vector<int>(n+1));
    int cnt = (n-1)*(n-2)/2 - k;
    for(int i = 2; i <= n; i++) node[1][i] = 1;
    if(cnt > 0){
        for(int i = 2; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                node[i][j] = 1;
                cnt--;
                if(cnt == 0){
                    i = n+1;
                    break;
                }
            }
        }
    }
    int m = (n-1)*(n-2)/2 - k + n - 1;
    cout << m << endl;
    rep(i,n+1) rep(j,n+1) if(node[i][j] == 1) cout << i << ' ' << j << endl;
}
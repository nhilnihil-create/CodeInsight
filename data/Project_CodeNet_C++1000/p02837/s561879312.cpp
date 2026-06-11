#include <bits/stdc++.h>
using namespace std;

int n;
int g[20][20];
int res = 0;
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j < n;j++){
            g[i][j] = -1;
        }
    }
    for(int i = 0;i<n;i++){
        int num;
        cin >> num;
        for(int j = 0;j<num;j++){
            int a,b;
            cin >> a >> b;
            --a;
            g[i][a] = b;
        }
    }
    int i = 0;
    int index1 = 0;
    for(i = 0;i < 1<<n;i++){
        vector<int> d(20);
        for(int j = 0;j<n;j++){
            if(i>>j&1) d[j] = 1;
        }
        bool ok = true;
        for(int j = 0;j<n;j++){
            if(d[j]){
                for(int k = 0;k<n;k++){
                    if(g[j][k] == -1) continue;
                    if(g[j][k] != d[k]){
                        ok = false;
                        break;
                    }
                }
            }
        }
        if(ok) {
            res = max(res,__builtin_popcount(i));
        }
                
    }
    cout << res << endl;
    return 0;
}
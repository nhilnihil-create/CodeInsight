#include <bits/stdc++.h>
#define ll long long
#define _ ios::sync_with_stdio(false);cout.tie(NULL);cin.tie(NULL);
using namespace std;

int main() { _
    int n, m, z, ans = 0; cin >> n >> m >> z;
    char arr[6][6];
    set <int> row, col;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    int count = 0;
    for(int i = 0; i < (1 << n); i++){
        for(int j = 0; j < n; j++){
            if((i >> j) & 1){
                row.insert(j);
            }
        }
        for(int k = 0; k < (1 << m); k++){
            for(int l = 0; l < m; l++){
                if((k >> l) & 1){
                    col.insert(l);
                }
            }
            for(int a = 0; a < n; a++){
                for(int b = 0; b < m; b++){
                    if(row.find(a) != row.end() || col.find(b) != col.end()){
                        continue;
                    }else{
                        if(arr[a][b] == '#'){
                            count++;
                        }
                    }
                }
            }
            if(count == z){
                ans++;
            }
            count = 0; col.clear();
        }
        row.clear();
    }
    cout << ans << endl;
}
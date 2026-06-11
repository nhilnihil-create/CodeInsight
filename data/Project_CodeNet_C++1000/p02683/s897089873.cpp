#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n, m, x;
    cin >> n >> m >> x;

    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0; i<n; i++){
        cin >> c[i];
        for(int j=0; j<m; j++){
            cin >> a[i][j];
        }
    }

    int min_mon = (1<<25);;
    for(int i=0; i<(1<<n); i++){
        vector<int> und(m, 0);
        int mon = 0;
        for(int j=0; j<n; j++){
            if(i & (1<<j)){
                mon += c[j];
                for(int k=0; k<m; k++){
                    und[k] += a[j][k];
                }
            }
        }

        // 判定
        bool flag = true;
        for(int k=0; k<m; k++){
            if(und[k] < x){
                flag = false;
                break;
            }
        }

        if(flag){
            min_mon = min(mon, min_mon);
        }
    }

    if(min_mon != (1<<25)){
        cout << min_mon << endl;
    }
    else{
        cout << -1 << endl;
    }

    return 0;
}
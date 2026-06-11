#include <bits/stdc++.h>
using namespace std;
using p = pair<int,int>;

int main(){
    int n;
    cin >> n;

    vector<vector<p>> v(n);

    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        v[i].resize(a);
        for(int j = 0; j < a; j++){
            cin >> v[i][j].first >> v[i][j].second;
            --v[i][j].first;
        }
    }

    int ans = 0;
    for(int bit = 0; bit < (1 << n); bit++){
        bool flag = true;
        for(int i = 0; i < n; i++){
            if(!(bit & (1 << i)))
                continue;
            for(p xy : v[i]){
                int x = xy.first;
                int y = xy.second;
                if(y == 1 && !(bit & (1 << x)))
                    flag = false;
                if(y == 0 && bit & (1 << x))
                    flag = false;
            } 
        }
        if(flag){
            int cnt = 0;
            for(int j = 0; j < n; j++){
                if(bit & (1 << j))
                    cnt++;
            }
            ans = max(ans, cnt);
        }
    }

    cout << ans << endl;

    return 0;
}
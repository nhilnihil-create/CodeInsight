#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool state[15][15];

int main(){
    int n;
    cin >> n;
    map<int, bool> state[n]; 
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        for(int j = 0; j < a; j++){
            int x, y;
            cin >> x >> y;
            x--;
            state[i][x] = y;
        }
    }
    int ans = 0;
    for(int i = 0; i < (1 << n); i++){
        bool honest[n];
        int cnt = 0;
        for(int j = 0; j < n; j++){
            // assume that person j is honest
            if(i >> j & 1){
                honest[j] = true;
                cnt++;
            } else {
                honest[j] = false;
            }
        }
        bool flag = true;
        for(int j = 0; j < n; j++){
            if(!honest[j]) continue;
            // verify whether j's statement is correct or not
            for(auto p : state[j]){
                if(honest[p.first] != p.second){
                    flag = false;
                }
            }
        }
        if(flag) ans = max(ans, cnt);
    }
    cout << ans << endl;
    return 0;
}
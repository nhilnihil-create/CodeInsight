#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<vector<P>> t(n);
    rep(i,n){
        int a;
        cin >> a;
        rep(j,a){
            int x, y;
            cin >> x >> y;
            x--;
            t[i].emplace_back(x,y);
        }
    }

    int ans = 0;
    rep(bit,1<<n){
        vector<int> p(n);
        int num = 0;
        rep(i,n) if(bit & (1<<i)){
            p[i] = 1;
            num++;
        }

        vector<int> test(n, -1);
        bool flag = true;
        rep(i,n) if(bit & (1<<i)){
            for(auto m : t[i]){
                int x = m.first, y = m.second;
                if(test[x] == -1){
                    test[x] = y;
                    continue;
                }
                if(test[x] != y){
                    flag = false;
                    break;
                }
            }
        }
        if(flag){
            rep(i,n){
                if(test[i] == -1) continue;
                if(test[i] != p[i]){
                    flag = false;
                    break;
                }
            }
        }
        if(flag) ans = max(ans, num);
    }
    cout << ans << endl;
}
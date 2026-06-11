#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using P = pair<int, int>;

vector<vector<P>> E;

int main(){
    int n;
    cin >> n;
    E.resize(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        for(int j = 0; j < a; j++){
            int x, y;
            cin >> x >> y;
            x--;
            E[i].emplace_back(x, y);
        }
    }
    int ans = 0;
    for(int S = 0; S != 1 << n; S++){
        bool ok = true;
        for(int i = 0; i < n; i++){
            if (!(S & 1 << i))continue;
            for(int j = 0; j < E[i].size(); j++){
                int x = E[i][j].first;
                int y = E[i][j].second;
                if (y == 0){
                    if (S & 1 << x){
                        ok = false;
                        break;
                    }
                }
                else{
                    if (!(S & 1 << x)){
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok)break;
        }
        if (!ok)continue;
        int nans = 0;
        int Sd = S;
        while(Sd != 0){
            if (Sd & 1)nans++;
            Sd >>= 1;
        }
        ans = max(ans, nans);
    }

    cout << ans << endl;
    return 0;
}
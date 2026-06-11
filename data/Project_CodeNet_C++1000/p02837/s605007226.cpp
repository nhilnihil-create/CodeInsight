#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> xy(n, vector<pair<int, int>>(0));
    rep(i, n){
        int A;
        cin >> A;
        rep(j, A){
            int x, y;
            cin >> x >> y;
            x--;
            xy[i].push_back(make_pair(x, y));
        }
    }
    int m = 0;
    bool flag = true;
    for(int temp = 0; temp < (1 << n); temp++){
        int ans = 0;
        flag = true;
        rep(i, n){
            if(temp & (1 << i)){
                rep(j, xy[i].size()){
                    int y = xy[i][j].second;
                    int x = xy[i][j].first;
                    if(y == 1){
                        if(!(temp & (1 << x))){
                            flag = false;
                            break;
                        }
                    }else{
                        if(temp & (1 << x)){
                            flag = false;
                            break;
                        }
                    }
                }
                if(!flag) break;
                else{
                    ans++;
                }
            }
        }
        if(flag){
            m = max(m, ans);
        }
    }
    cout << m << endl;
}
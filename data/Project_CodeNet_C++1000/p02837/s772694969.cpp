#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main(){
    int n,x,y,l; cin >> n;
    ll sum = 0, ans = 0;
    bool flag = true;
    vector<int> v(n,0);
    vector<vector<pair<int,int>>> a(n);

    rep(i,n){
        cin >> l;
        rep(j,l){
            cin >> x >> y;
            a[i].push_back(make_pair(x,y));
        }
    }

    for(int bit = 0; bit < (1 << n); ++ bit){

        rep(i,n) v[i] = 0;
        sum = 0;
        flag = true;

        for(int i = 0; i < n; ++i){
            if(bit & (1 << i)){
                v[i] = 1;
                sum ++;
            }
        }

        for(int i = 0; i < n; i ++){
            if(v[i] == 1){
                for(int j = 0; j < a[i].size(); j ++){
                    if(v[a[i][j].first-1] != a[i][j].second) flag = false;
                }
            }
        }

        if(flag) ans = max(sum,ans);
    }

    cout << ans;
    //bit全探索で矛盾が起こらない最大値を求める*/

}
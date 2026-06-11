#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>
#include<map>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<P> dec[n];
    rep(i, n){
        int a;
        cin >> a;
        rep(j, a){
            int x, y;
            cin >> x >> y;
            x--;
            dec[i].push_back(P(x, y));
        }
    }
    int ans = 0;
    rep(i, 1<<n){
        bool flag = true;
        rep(j, n){
            if ((i>>j)&1){
                rep(k, dec[j].size()){
                    if(((i>>dec[j][k].first)&1) != dec[j][k].second) flag=false;
                }
            }
        }
        if(flag){
            int ans_ = 0;
            rep(j, n){
                if((i>>j)&1)ans_++;
            }
            ans = max(ans, ans_);
        }
    }
    cout << ans << endl;
}
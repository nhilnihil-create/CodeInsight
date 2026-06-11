#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef vector<int> V;
typedef pair<int,int> P;
typedef vector<vector<int>> Graph;

int main() {
    int ans = 0;
    int n;
    cin >> n;
    vector<vector<P>> v(n);
    rep(i,n){
        int a;
        cin >> a;
        rep(j,a){
            int x,y;
            cin >> x >> y;
            x--;
            v[i].push_back(make_pair(x,y));
        }
    }
    for(int bit=0;bit<(1<<n);bit++){
        bool flag = true;
        for(int i=0;i<n;i++){
            if(bit&(1<<i)){
                for(auto j : v[i]){
                    if(!((j.second==1&&(bit&(1<<j.first)))||(j.second==0&&!(bit&(1<<j.first))))) flag = false;
                }
            }
        }
        if(flag) ans = max(ans,__builtin_popcount(bit));
    }
    cout << ans << endl;
}
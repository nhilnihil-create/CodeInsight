#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
#define int long long
using P = pair<int,int>;
signed main(){
    int n;cin >> n;
    vector<P> res;
    rep(i,n){
        int x,l;cin >> x >> l;
        res.emplace_back(x-l,x+l);

    }
    int ans = n;
    sort(res.begin(),res.end());
    vector<int> hidari;
    for(int i = n-1;i >= 0 ;i--){
        if(hidari.size()&&res[i].second > hidari.back()){
            ans--;
            continue;
        }
        hidari.emplace_back(res[i].first);



        
    }
    cout << ans << endl;
    return 0;
}
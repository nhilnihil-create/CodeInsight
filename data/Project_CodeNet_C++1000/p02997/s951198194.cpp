#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n,k;
    cin >> n >> k;
    ll sup = (n-1)*(n-2)/2;
    if(k > sup){
        cout << -1 << endl;
        return 0;
    }
    vector<pair<ll,ll>> ans;
    for(i = 2;i <= n;++i){
        ans.emplace_back(1,i);
    }
    bool flag = false;
    for(i = 2;i <= n-1;++i){
        for(j = i+1;j <= n;++j){
            if(sup == k){
                flag = true;
                break;
            }
            ans.emplace_back(i,j);
            --sup;
        }
        if(flag) break;
    }
    cout << ans.size() << endl;
    for(i = 0;i < ans.size();++i){
        cout << ans.at(i).first << " " << ans.at(i).second << endl;
    }
    return 0;
}
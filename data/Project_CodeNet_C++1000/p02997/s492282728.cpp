#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
int main(){
    int n,k;cin >> n >> k;
    vector<P> ans;
    if((n-1)*(n-2)/2<k){
        cout << -1 << endl;
        return 0;
    }
    for(int i=0;i<n-1;i++) ans.push_back({i+1,n});
    int need=(n-1)*(n-2)/2-k;
    vector<P> side;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            side.push_back({i+1,j+1});
        }
    }
    for(int i=0;i<need;i++) ans.push_back(side[i]);
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}
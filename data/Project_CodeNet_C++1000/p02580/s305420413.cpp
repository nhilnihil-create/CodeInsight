#include<bits/stdc++.h>

// @author : sam000013

#define int long long
#define PI 3.14159265
#define pb(x) push_back(x)
#define PI 3.14159265
#define all(v) v.begin(), v.end()
#define endl cout<<"\n" 
#define dbg(x) cout<<#x<<" "<<x;endl;
#define bye endl;return
#define uni 1.000000
using namespace std;

const int mod = 1000000007;
// template<typename T>

// void debug(vector<T> x){
//     for(auto e:x){
//         cout<<e<<" ";
//     }
//     cout<<"\n";
// }
/*


*/

vector<int> column(300005, 0);
multiset<int> best;
vector<int> inRow[300005];

void upd(int pos, int delta){
    best.erase(best.find(column[pos]));
    column[pos] += delta;
    best.insert(column[pos]);
}
void solve(){
    int h,w,m;
    cin>>h>>w>>m;

    for(int i=0; i<m; i++){
        column[i] = 0;
        best.insert(0);
    }

    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        x--; y--;
        inRow[x].push_back(y);
        upd(y,1);
    }
    
    int ans = 0;
    for(int i=0; i<h; i++){
        int cur = inRow[i].size();
        for(auto x:inRow[i]){
            upd(x, -1);
        }
        
        if(best.size())
        cur += *(best.rbegin());
        // cout<<cur<<" ";
        ans = max(ans, cur);
        for(auto x:inRow[i]){
            upd(x, 1);
        }
    }
    cout<<ans;bye;



}

signed main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int t = 1;
    // cin>>t;
    for(int i=1; i<=t; i++){
        solve();
    }
    return 0;
}

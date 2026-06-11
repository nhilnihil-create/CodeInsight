#include<bits/stdc++.h>
using namespace std;
using Int = long long;
Int N,D,A;
#define rep(i,n) for(int i=0;i<n;i++)
int getid(vector<Int>&v,int id){
    Int x =v[id] - 2 * D;
    auto itr = lower_bound(v.begin(), v.end(),x);
    if(itr == v.begin()) return -1;
    return (int)(--itr - v.begin());
    
}
int main(){
    cin >> N >> D >> A;
    vector<pair<Int,Int>>input(N);
    for(auto& p : input)
        cin >> p.first >> p.second;
    sort(input.begin(),input.end());
    Int ans = 0;
    vector<Int>dp(N,0LL),grid;
    for(auto p : input) grid.emplace_back(p.first);
    for(int i = 0; i < N; ++i){
        if(i)dp[i] += dp[i-1];
        int idx = getid(grid,i);
        Int culm = dp[i];
        if(idx != -1){
            culm -= dp[idx];
        }
        if(input[i].second <= culm * A){
            
        } else {
            Int dif = input[i].second - culm * A;
            Int t = (dif / A)  + (dif % A  == 0 ? 0 : 1);
            ans += t;
            dp[i] += t;
            
        }
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n;cin>>n;
    vector<pair<int,int>> arm;
    rep(i,n){
        int x,l;cin>>x>>l;
        arm.emplace_back(x+l, x-l);
    }
    
    sort(arm.begin(), arm.end());
    int right = arm[0].first;
    int ans = 1;
    for(int i=1; i<n; i++){
        if(arm[i].second>=right){
            ans++;
            right = arm[i].first;
        }
    }
    
    cout << ans << endl;
    return 0;
}
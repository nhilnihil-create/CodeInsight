#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
int main(){
    int x,n,a;
    cin >> x >> n;
    vector<int> d(102);
    
    rep(i,n){
        cin >> a;
        d[a]=1;
    }
    P ans = {9999,-1};
    for(int i = 0; i < 102; i++){
        if (d[i]==1) continue;
        int dis = abs(x-i);
        ans = min(ans, P(dis, i));
    }
    cout << ans.second << endl;
    return 0;
}

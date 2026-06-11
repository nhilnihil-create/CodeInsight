#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using p = pair<int,int>;
static const long long INF = 100000000;
int main(){
    int n,k;
    cin >> n >> k;
    vector<long long> monster(n);
    rep(i,n){
        cin >> monster[i];
    }
    sort(monster.begin(),monster.end());
    long long ans;
    ans = 0;
    int x = n-k;
    if (x < 1){
        cout << 0 << endl;
        return 0;
    }
    else{
        rep(i,x){
            ans += monster[i];
        }
        cout << ans << endl;
        return 0;
    }
}
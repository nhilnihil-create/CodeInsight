#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;

int main(){
    int n;
    cin >> n;
    vi x(n), l(n);
    rep(i,n) cin >> x[i] >> l[i];
    vector<pair<int,int>> arm(n);
    rep(i,n){
        arm[i].first=x[i]+l[i];
        arm[i].second=x[i]-l[i];
    }
    sort(arm.begin(),arm.end());
    int ans=0;
    int now=-1e9;
    rep(i,n){
        if(now<=arm[i].second){
            ans++;
            now=arm[i].first;
        }
    }
    cout << ans << endl;
}
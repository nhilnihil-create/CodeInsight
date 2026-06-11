#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

const int INF = 2e9;

int main(){
    int n;
    cin >> n;
    vector<string> s(n);
    map<string,ll> x;
    ll ans = 0;
    rep(i,n){
        cin >> s[i];
        sort(s[i].begin(),s[i].end());
        x[s[i]]++;
        ans += (x[s[i]]-1);
    }
    cout << ans << endl;
}
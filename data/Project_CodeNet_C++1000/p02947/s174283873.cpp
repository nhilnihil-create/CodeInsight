#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    map<string, int> ana;
    rep(i,n){
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        ana[s]++;
    }

    ll ans = 0;
    for(auto p : ana){
        ll num = p.second;
        ans += num*(num-1)/2;
    }
    cout << ans << endl;
}
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep2(i,a,n) for(int i = (a);i < (n);i++)
#define rep(i,n) rep2(i,0,n)
#define INF (1LL << 60)

int main(void){
    int n;
    cin >> n;
    string s[n];
    map<string,int> mp;
    rep(i,n){
        cin >> s[i];
        sort(s[i].begin(),s[i].end());
        mp[s[i]]++;
    }
    
    ll ans = 0;
    for(auto p:mp){
        if(p.second <= 0)continue;
        for(int i = 1;i < p.second;i++)ans += i; 
    }
    
    cout << ans << endl;
}
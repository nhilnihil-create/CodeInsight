#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;
using vii=vector<vector<int>>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=1e9+7;

template<typename T> bool chmax(T &a,const T b){if(a < b){a=b; return true;} return false;}
template<typename T> bool chmin(T &a,const T b){if(a > b){a=b; return true;} return false;}



int main(){
    int n; cin >> n;
    vector<string> s(n);
    for(auto &x: s) cin >> x;

    map<vi, ll> mp;
    for(int i=0; i<n; i++){
        vi cnt(26, 0);
        for(int j=0; j<10; j++) cnt[s[i][j]-'a']++;
        mp[cnt]++;
    }
    ll ans=0;
    for(auto p: mp){
        ans+=p.second*(p.second-1)/2;
    }
    cout << ans << endl;
    return 0;
}
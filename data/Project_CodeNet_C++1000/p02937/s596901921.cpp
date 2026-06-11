#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
//#define MOD 1000000007
const int INF = 1LL<<30;

vector<vector<int>> cnt(26);

int main() {
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();

    rep(i,n){
        cnt[s[i]-'a'].push_back(i);        
    }

    ll ans=0;
    int x=-1;
    rep(i,m){
        int c=t[i]-'a';
        if(cnt[c].empty()){
            cout<<-1<<endl;
            return 0;
        }
        int ind=upper_bound(all(cnt[c]),x)-cnt[c].begin();
        if(ind==cnt[c].size()){
            ans+=n;
            x=cnt[c][0];
        }
        else x=cnt[c][ind];
    }

    cout<<ans+x+1<<endl;
}
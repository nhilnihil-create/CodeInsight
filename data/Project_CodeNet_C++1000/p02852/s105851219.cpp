#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007;



int main() {
    int N,M;
    cin>>N>>M;
    string S;
    cin>>S;
    vector<int> canr(0);
    rep(i,N+1){
        if(S.at(i)=='0'){
            canr.pb(i);
        }
    }
    int count=0,now=N;
    vector<int> ans(0);
    while(now>0){
        auto nex=lower_bound(canr.begin(),canr.end(),now-M);
        int tugi=*nex;
        if(tugi>=now){
            cout<<-1<<endl;return 0;
        }
        ans.pb(now-tugi);
        now=tugi;
        count++;
    }
    reverse(ans.begin(),ans.end());
    rep(i,sz(ans)){
        cout<<ans.at(i)<<" ";
    }
    cout<<endl;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

vector<vector<int>> p(26);

int main(){
    string s,t;
    cin>>s>>t;

    int n=s.size();
    int m=t.size();
    rep(i,n){
        p[s[i]-'a'].push_back(i);
    }

    /*
    rep(i,26){
        if(p[i].size()==0) continue;
        rep(j,p[i].size()) cout<<p[i][j]<<" ";
        cout<<endl;
    }*/

    rep(i,m){
        if(p[t[i]-'a'].size()==0){
            cout<<-1<<endl;
            return 0;
        }
    }

    ll ans=0;
    int po=-1;
    rep(i,m){
        int x=t[i]-'a';
        int ind=upper_bound(all(p[x]),po)-p[x].begin();
        //cout<<ind<<" "<<po<<endl;
        if(ind==p[x].size()){
            ans+=n;
            po=p[x][0];
        }
        else{
            po=p[x][ind];
        }
    }
    ans+=po;

    cout<<ans+1<<endl;
}



#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

vector<vector<int>> cnt(26);

int main(){
    string s,t;
    cin>>s>>t;
    ll n=s.size();
    ll m=t.size();

    rep(i,n){
        cnt[s[i]-'a'].push_back(i);
    }

    rep(i,m){
        if(cnt[t[i]-'a'].size()==0){
            cout<<-1<<endl;
            return 0;
        }
    }

    ll q=0;
    int pre=-1;
    rep(i,m){
        int id=upper_bound(all(cnt[t[i]-'a']),pre)-cnt[t[i]-'a'].begin();
        if(id==cnt[t[i]-'a'].size()){
            q++;
            pre=cnt[t[i]-'a'][0];
        }
        else{
            pre=cnt[t[i]-'a'][id];
        }
        //cout<<id<<" "<<pre<<endl;
    }

    //cout<<q<<" "<<pre<<endl;
    ll ans=q*n+pre+1;
    cout<<ans<<endl;
}
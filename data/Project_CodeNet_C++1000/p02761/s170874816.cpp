#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(k,i,n) for(ll i=k;i<n;++i)
#define pb push_back
int main(void){
    ll n,m;
    cin>>n>>m;
    if(n==1&&m==0){
        cout<<0<<endl;
        return 0;
    }
    string ans="";
    rep(0,i,n)ans+=" ";
    vector<pair<ll,char>>p(m);
    rep(0,i,m){
        cin>>p[i].first>>p[i].second;
        --p[i].first;
    }
    sort(p.begin(),p.end());
    rep(0,i,m){
        ll s=p[i].first;
        char c=p[i].second;
        if(s==0&&c=='0'&&n!=1){
            cout<<-1<<endl;
            return 0;
        }
        if(ans[s]==' ')ans[s]=c;
        else if(ans[s]!=c){
            cout<<-1<<endl;
            return 0;
        }
    }
    rep(0,i,n){
        if(ans[i]==' '){
            if(i==0){
                ans[i]='1';
            }else{
                ans[i]='0';
            }
        }
    }
    rep(0,i,n)cout<<ans[i];
}
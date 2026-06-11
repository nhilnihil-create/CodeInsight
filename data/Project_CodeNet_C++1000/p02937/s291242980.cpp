//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main() {
    string s,t; cin>>s>>t;
    ll ans=1,n=s.size();
    vector<vector<ll>> pos(26,vector<ll>(1,n+1));
    rep(i,n) pos[s[i]-'a'].push_back(i+1);
    rep(i,26) sort(al(pos[i]));
    ll cnt1=0,cnt2=0;
    rep(i,t.size()){
        ll ind=t[i]-'a';
        ll l=0,r=pos[ind].size()-1,ce;
        if(r==0){
            ans=-1; break;
        }
        while(l!=r){
            ce=(l+r)/2;
            if(pos[ind][ce]>cnt2) r=ce;
            else l=ce+1;
        }
        if(pos[ind][l]!=n+1) cnt2=pos[ind][l];
        else{
            cnt1++; cnt2=pos[ind][0];
        }  
    }
    cout<<(ans!=-1 ? cnt1*n+cnt2 : ans)<<endl;
}
#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

#define int ll

template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os<<"("<<p.first <<", "<<p.second<<")";
  return os;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n;cin>>n;
    map<int,int> mp,mpp;
    rep(i,n){
        int a;cin>>a;
        mp[a]++;
    }
    for(auto p:mp) mpp[p.second]++;
    vector<pair<int,int>> v;
    v.push_back(make_pair(INF,0));
    for(auto p:mpp)v.push_back(p);
    sort(ALL(v));reverse(ALL(v));

    vector<int> ans(n+1);
    int var=(int)mp.size();
    ans[var]=v.back().first;
    for(int i=var+1;i<=n;i++) ans[i]=0;


    for(int k=var-1;k>1;k--){
        auto p=v.back();v.pop_back();

        int rem=p.first;
        if(p.second>1)v.push_back(make_pair(p.first,p.second-1));
        while(rem){
            auto pn=v.back();v.pop_back();// 今均すの
            int need=(v.back().first-pn.first)*pn.second;
            if(rem>=need){
                rem-=need;
                auto pnn=v.back();v.pop_back();
                pnn.second=pnn.second+pn.second;
                v.push_back(pnn);
            }else{
                pair<int,int> fs=make_pair(pn.first+rem/pn.second+1,rem%pn.second);
                if(fs.second!=0){
                    if(v.back().first==fs.first){
                        fs.second+=v.back().second;v.pop_back();
                        v.push_back(fs);
                    }else{
                        v.push_back(fs);
                    }
                }
                pair<int,int> sc=make_pair(pn.first+rem/pn.second,pn.second-rem%pn.second);
                if(v.back().first==sc.first){
                    sc.second+=v.back().second;v.pop_back();
                    v.push_back(sc);   
                }else{
                    v.push_back(sc);
                }
                rem=0;
            }
        }

        ans[k]=v.back().first;
    }
    ans[1]=n;
    for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
    return 0;
}

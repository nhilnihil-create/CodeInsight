#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define repp(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back()
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    string s,t; cin >> s >> t;
    vector<int> ok[50];
    rep(i,s.size()){
        int idx=s[i]-'a';
        ok[idx].pb(i);
    }
    int n=t.size();
    vector<int> v(n);
    rep(i,t.size()){
        int idx=t[i]-'a';
        if(ok[idx].size()==0){
            cout << -1 << endl;
            return 0;
        }
        if(i==0){
            v[i]=ok[idx][0];
        }else{
            int pl=v[i-1];
            int p=upper_bound(ALL(ok[idx]),pl)-ok[idx].begin();
            if(p==ok[idx].size()) v[i]=ok[idx][0];
            else v[i]=ok[idx][p];
        }
    }
    ll cnt=0;
    rep(i,n-1){
        if(v[i]>=v[i+1]) cnt++;
    }
    cout << (ll)(cnt*s.size())+(ll)v[n-1]+1LL << endl;
    
}

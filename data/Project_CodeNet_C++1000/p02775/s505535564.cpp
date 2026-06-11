#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(10) << num << endl;
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

signed main(){
    string s; cin >> s;
    ll ans=0;
    bool ue=0;
    for(int i=s.size()-1;i>=0;i--){
        int x=s[i]-'0';
        x+=ue;
        if(x==5){
            if(i>0&&(s[i-1]-'0')>4) ue=1;
            else ue=0;
            ans+=5;
        }else{
            ans+=min(x,10-x);
            if(x<5) ue=0;
            else ue=1;
        }
    }
    ans+=ue;
    cout << ans << endl;
}


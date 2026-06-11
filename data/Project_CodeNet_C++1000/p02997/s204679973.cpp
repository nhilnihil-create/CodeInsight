#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可
//乗算の際にオーバーフローに注意せよ！！（適切にmodをとれ）
//制約をよく読め！

const ll INF=1e18;

signed main(){
    int n,k;
    cin>>n>>k;
    if(k>(n-1)*(n-2)/2) cout<<-1<<endl;
    else{
        vector<pair<int,int>> p;
        for(int i=2;i<=n;i++) p.push_back(make_pair(1,i));
        int m=(n-1)*(n-2)/2-k;
        int u=2,v=3;
        while(m--){
            p.push_back(make_pair(u,v));
            if(v==n){
                u++;
                v=u+1;
            }else v++;
        }
        cout<<p.size()<<endl;
        for(auto pp:p) cout<<pp.ft<<' '<<pp.sc<<endl;
    }
}
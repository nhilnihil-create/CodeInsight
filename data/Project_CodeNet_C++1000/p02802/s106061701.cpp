#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,m;cin>>n>>m;
    map<int,int> mp;
    vector<bool> AC(n,false);
    ll res1=0,res2=0;
    rep(i,m){
        int p;string s;cin>>p>>s;
        p--;
        if(s=="AC"){
            AC[p]=true;
        }else{
            if(AC[p])continue;
            mp[p]++;
        }
    }
    rep(i,n){
        if(AC[i]){
            res1++;
            res2+=mp[i];
        }
    }
    cout<<res1<<" "<<res2<<endl;
}
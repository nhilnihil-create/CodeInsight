#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    string s;cin>>s;
    ll res=0;
    vector<ll> a(s.size()+1,0);
    rep(i,s.size()){
        if(s[i]=='<') chmax(a[i+1],a[i]+1);
    }
    reverse(s.begin(),s.end());
    reverse(a.begin(),a.end());
    rep(i,s.size()){
        if(s[i]=='>') chmax(a[i+1],a[i]+1);
    }
    rep(i,s.size()+1){
        res+=a[i];
    }
    cout<<res<<endl;
}
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
const ll mod=1e+9+7;
int main(void){
    int n;string s;cin>>n>>s;
    if(s[0]=='W'||s[s.size()-1]=='W'){
        cout<<0<<endl;
        return 0;
    }
    vector<int> t(s.size());
    t[0]=0;//0はL,1はR
    queue<int> que;
    rep(i,s.size()-1){
        if(s[i+1]==s[i]){
            t[i+1]=1-t[i];
        }else{
            t[i+1]=t[i];
        }
        if(t[i+1]==1)que.push(i+1);
    }
    if(que.size()!=n){
        cout<<0<<endl;
        return 0;
    }
    ll res=1;
    rep(i,n) res=(res*(i+1))%mod;
    rep(i,n){
        ll x=que.front();que.pop();
        res*=(x-2*i);
        res%=mod;
    }
    cout<<res<<endl;
}

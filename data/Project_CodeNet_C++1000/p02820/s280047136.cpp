#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n,k;cin>>n>>k;
    ll r,s,p;cin>>r>>s>>p;
    string t;cin>>t;
    ll d[3]={p,r,s};
    char g[3]={'r','s','p'};
    ll res=0;
    vector<char> l;
    rep(i,n){
        char c=t[i];
        rep(j,3){
            if(c==g[j]){
                if(i<k||l[i-k]!=g[j]){
                    res+=d[j];
                    l.push_back(c);
                }else{
                    l.push_back('n');
                }
            }
        }
    }
    cout<<res<<endl;
}

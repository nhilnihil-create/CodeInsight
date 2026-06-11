#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    string s,t;cin>>s>>t;
    vector<vector<ll>> v(26);
    rep(i,s.size())v[s[i]-'a'].push_back(i+1);
    ll tmp1=0,tmp2=-1;
    rep(i,t.size()){
        int x=t[i]-'a';
        int sz=v[x].size();
        if(v[x].size()==0){
            cout<<-1<<endl;
            return 0;
        }
        if(v[x][sz-1]<=tmp2){
            tmp2=v[x][0];
            tmp1++;
            continue;
        }
        auto& vv=v[x];
        auto itr=upper_bound(vv.begin(),vv.end(),tmp2);
        int k=itr-vv.begin();
        ll y=v[x][k];
        tmp2=y;
    }
    ll res=tmp1*s.size()+tmp2;
    cout<<res<<endl;
}
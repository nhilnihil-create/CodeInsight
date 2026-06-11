#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    ll n=s.size();
    vector<int> t(n+1);
    rep(i,n) {
        if (s[i]=='<') t[i+1]=t[i]+1;
    }
    invrep(i,n) {
        if (s[i]=='>') t[i]=max(t[i],t[i+1]+1); 
    }
    ll ans=0;
    rep(i,n+1) ans+=t[i];
    cout << ans << endl;
    

   
    return 0;   
}
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
    ll k;
    cin >> k;
    ll n=s.size();
    int cnt=1;
    vector<ll> c;
    rep(i,n-1) {
        if (s[i]==s[i+1]) ++cnt;
        else {
            c.push_back(cnt);
            cnt=1;
        }
    }
    if (cnt>1) c.push_back(cnt);
    int m=c.size();
    ll ans=0;
    if (s[0]!=s[n-1]) {
        rep(i,m) {
            ans+=ll(c[i]/2)*k;
        }
    } else if (m>2) {
        repr(i,1,m-1) {
            ans+=ll(c[i]/2)*k; 
        }
        ans+=ll(c[0]/2)+ll(c[m-1]/2)+ll((c[0]+c[m-1])/2)*(k-1);
    } else {
        ans=(k*n)/2;
    }
    cout << ans << endl;


    
    return 0;   
}
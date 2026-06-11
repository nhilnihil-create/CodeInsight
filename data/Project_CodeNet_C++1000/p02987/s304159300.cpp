#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,ll>
const ll MOD=998244353;
const int INF=1e9;
const double PI=acos(-1);


int main() {
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    sort(s.begin(),s.end());
    bool flag=1;
    rep(i,3) {
        if ((s[i]!=s[i+1]) ^ (i%2!=0)) flag=0;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0; 
}

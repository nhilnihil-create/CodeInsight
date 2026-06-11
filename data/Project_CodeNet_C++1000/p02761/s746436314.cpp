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

    int n,m;
    cin >> n >> m; 
    vector<int> t(n,-1);
    bool flag=1;
    rep(i,m) {
        int s,c;
        cin >> s >> c;
        if (t[s-1]!=-1 && c!=t[s-1]) flag=0;
        else t[s-1]=c;
    }
    if (t[0]==0 && n>1) flag=0;
    if (flag) {
        if (t[0]==-1 && n>1) t[0]=1;
        rep(i,n) {
            if (t[i]==-1) t[i]=0;
            cout << t[i];
        }
        cout << endl;
    } else cout << -1 << endl;
    
   
    return 0;  
}
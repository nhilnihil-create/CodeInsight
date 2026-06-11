#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const ll MOD=1e9+7;
const int INF=2e9;
const double PI=acos(-1);

const int MAX=200010;


int main() {
    ios_base::sync_with_stdio(false); 

    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    vector<vector<int>> cnt(h,vector<int>(w,INF));
    if (s[0][0]=='.') cnt[0][0]=0;
    else cnt[0][0]=1;
    rep(i,h) {
        rep(j,w) {
            if (j<w-1) {
                if (s[i][j]==s[i][j+1]) cnt[i][j+1]=min(cnt[i][j+1],cnt[i][j]);
                else cnt[i][j+1]=min(cnt[i][j+1],cnt[i][j]+1); 
            }
            if (i<h-1) {
                if (s[i][j]==s[i+1][j]) cnt[i+1][j]=min(cnt[i+1][j],cnt[i][j]);
                else cnt[i+1][j]=min(cnt[i+1][j],cnt[i][j]+1); 
            }
        }
    }
    cout << (cnt[h-1][w-1]+1)/2 << endl;
    
    return 0;
}

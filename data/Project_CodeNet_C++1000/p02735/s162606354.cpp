#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(ll i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=2e9;;


int main() {
    ios_base::sync_with_stdio(false); 
    
    int h,w;
    cin >> h >> w;
    vector<string> s(h);
    rep(i,h) cin >> s[i]; 
    vector<vector<int>> cnt(h,vector<int>(w,INF));
    priority_queue<pair<int,P>,vector<pair<int,P>>,greater<pair<int,P>>> pq;
    
    cnt[0][0]=0;
    pq.push({0,{0,0}});
    vector<int> di={0,1},dj={1,0};
    while (!pq.empty()) {
        pair<int,P> now=pq.top();
        int i=now.second.first,j=now.second.second;
        pq.pop();
        rep(k,2) {
            int ni=i+di[k],nj=j+dj[k];
            if (ni<h && nj<w) {
                int cost=cnt[i][j];
                if (s[ni][nj]=='#' && s[i][j]=='.') ++cost;
                if (cnt[ni][nj]>cost) {
                    cnt[ni][nj]=cost;
                    pq.push({cnt[ni][nj],{ni,nj}});
                }
            }
        }
    }
    int sc=(s[0][0]=='.')?0:1;
    cout << cnt[h-1][w-1]+sc << endl;
    
    return 0;
}
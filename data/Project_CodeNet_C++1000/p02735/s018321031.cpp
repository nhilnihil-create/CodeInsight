#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<tuple>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 1000000007;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
typedef pair<P,int> PP;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define Per(i,sta,n) for(int i=n-1;i>=sta;i--)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
int dx[2]={1,0};
int dy[2]={0,1};

int h,w;
string s[110];
int S[110][110];
int d[110][110];

void solve(){
    cin >> h >> w;
    rep(i,h){
        cin >> s[i];
    }
    Rep(i,1,w) S[0][i]=-1;
    rep(i,h){
        rep(j,w){
            if(s[i][j]=='#') S[i+1][j]=1;
        }
    }
    rep(i,h+1){
        rep(j,w){
            d[i][j]=mod;
        }
    }
    deque<PP> que={};
    que.push_back(PP(P(0,0),0));
    while(!que.empty()){
        int y=que[0].first.first,x=que[0].first.second,l=que[0].second;
        que.pop_front();
        if(d[y][x]!=mod) continue;
        d[y][x]=l;
        //cout << y << " " << x << " " << d[y][x] << endl;
        rep(k,2){
            int ny=y+dy[k],nx=x+dx[k];
            if(ny>=h+1 && nx>=w) continue;
            if(S[ny][nx]==-1) continue;
            if(S[y][x]==0 && S[ny][nx]==1){
                //cout << "a " << ny << " " << nx << endl;
                que.push_back(PP(P(ny,nx),l+1));
            } 
            else{
                //cout << "b " << ny << " " << nx << endl;
                que.push_front(PP(P(ny,nx),l));
            }
        }
    }
    // rep(i,h+1){
    //     rep(j,w){
    //         cout << d[i][j] << " ";
    //     }
    //     cout << "" << endl;
    // }
    cout << d[h][w-1] << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(50);
    solve();
}
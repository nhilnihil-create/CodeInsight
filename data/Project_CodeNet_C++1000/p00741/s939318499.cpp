#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<set>
#include<complex>
#define vi vector<int>
#define vvi vector<vector<int> >
#define ll long long int
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define ld long double
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define CC puts("-------ok--------");
#define all(in) in.begin(), in.end()
#define bv vector<bool>
using namespace std;
typedef pair<int, int> PI;
#define MAX 99999999
vvi v(60,vi(60,0));
int w,h;
int mx[]={-1,0,1};
int my[]={-1,0,1};
void dfs(int y,int x){
        if (!v[y][x])return;
        if(v[y][x]){
            v[y][x]=0;
            rep(p,3)rep(q,3){
                int tx=x+mx[p]; int ty=y+my[q];
                if(0<=tx&&tx<w&&0<=ty&&ty<h&&v[ty][tx]!=0){
                    dfs(ty,tx);
                }
            }
        }
    }
int main(){
    while(cin>>w>>h,w+h){
        rep(i,h)rep(j,w)cin>>v[i][j];
        int ans=0;
        rep(i,h)rep(j,w){
            if(v[i][j]){dfs(i,j);
            ans++;
            }
        }
        cout<<ans<<endl;
        rep(i,60)rep(j,60)v[i][j]=0;
    }
}
#include <iostream>
#include<time.h>
#include<string>
#include<cstring>
#include <cstdio>
#include<utility>
#include<algorithm>
#include<vector>
#include<cmath>
#include<map>
#include<bitset>
#include<queue>
#include<stack>
#include<set>
#include <limits>
#include <climits>
#include <numeric>
#include<cassert>
#include<cctype>
#include<iterator>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef unsigned long long LL;
typedef vector<ll>VI;
typedef vector<bool>VB;
typedef pair<ll,ll>P;
typedef pair<double,double>P_D;
#define VV(T) vector<vector<T>>
#define PI 3.1415926535897932384626433832795
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define reprev(i, n) for (ll i = (ll)n - 1; i >= 0; i--)
#define bitrep(bit,A) for(int bit=A; ;bit=(bit-1)&A)
#define ALL(a)  (a).begin(),(a).end()
#define SZ(a) (ll)((a).size())
#define c_max(a, b) (((ll)a)>((ll)b)?(a):(b))
#define c_min(a,b) (((ll)a)<((ll)b)?(a):(b))
#define chmax(x,a) x=c_max(x,a)
#define chmin(x,a) x=c_min(x,a)
#define vmax(v) *max_element(ALL(v))
#define vmin(v) *min_element(ALL(v))
#define SORT(c) stable_sort(ALL(c))
#define $(x) {cout<<#x<<" = " <<(x)<<endl;}
#define fi first
#define se second
#define MAX 100100//5
#define MAX2 200100
#define MAX_6 1001001//6
#define MAX_7 10010010//7
#define SENTINEL 2000000000//9
#define NIL -1
#define MOD 1000000007
#define INF 1<<30
#define INFTY 1000000000000000001LL
#define MAX_INT INT_MAX
#define Endl '\n'
#define greater greater<int>()
inline ll GCD(ll a,ll b){return b?GCD(b,a%b):a;}
inline ll lcm(ll a,ll b){return a*b/GCD(a,b);}
using Graph=vector<vector<int> >;//int と P
// g++ -o a a.cpp -Wall -lm -std=c++14
int n,x,y;
int main(){
    cin>>n>>x>>y;
    x--;y--;
    Graph G(n);
    G[x].push_back(y);
    G[y].push_back(x);
    rep(i,n-1){
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }
    queue<int> q;
    int path[n+1][n+1];
    memset(path,-1,sizeof(path));
    for(int i=0;i<n;i++){
            queue<int> q;
            q.push(i);
            path[i][i]=0;
            while(!q.empty()){
                int v=q.front();
                q.pop();
                for(auto u:G[v]){
                    if(path[i][u]!=-1)continue;
                    q.push(u);
                    path[i][u]=path[i][v]+1;                    
                }
            }
    }
    int s[MAX];
    memset(s,0,sizeof(s));
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            s[path[i][j]]++;
        }
    }
    for(int i=1;i<n;i++){
        cout<<s[i]<<endl;
    }
}
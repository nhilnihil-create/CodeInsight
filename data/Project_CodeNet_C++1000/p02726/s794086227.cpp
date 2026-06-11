#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>
#include<set>
#include <cassert>
 
using namespace std;
 
#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define P(p) cout<<(p)<<endl;
#define PP(p) cout<<(p)<<" ";
#define INF 1e18

typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;
//int dy[8]={1,1,1,0,-1,-1,-1,0};
//int dx[8]={-1,0,1,1,1,0,-1,-1};
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int n,x,y;


int cnt[2001];
//int a[2001][2001];
int dis(int a,int b){
    int t1 = abs(a-b);
    int t2 = abs(a-x)+1+abs(b-y);
    int t3 = abs(a-y)+1+abs(b-x);
    return min({t1,t2,t3});
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>x>>y;
    for(int i = 1; i<=n;i++){
        for(int j = i;j<=n;j++){
            int k= dis(i,j);
            cnt[k]++;
        }
    }
    for(int i = 1;i<n;i++){
        cout << cnt[i] << endl;
    }
    return 0;
}

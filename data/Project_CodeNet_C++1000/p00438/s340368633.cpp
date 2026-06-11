#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>
#include <complex>
#include <memory>
#include <functional>
 
using namespace std;
 
#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i <= n; i++)
#define REP2(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define F(i,j,k) fill(i[0],i[0]+j*j,k)
#define P(p) cout<<(p)<<endl;
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define INF 1<<25
#define pb push_back
 
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef pair<long,long> pll;
typedef long long LL;
typedef long long int LLI;

int solve(int a,int b);

int x,y,n,ans,c,d;
int road[20][20];
int memo[20][20];
int dx[2] = {0,1};
int dy[2] = {1,0};

int main()
{
    int i;
    
    while(cin >> x >> y, x||y){
        ans = 0;
    
        
        REP(i,1,y){
            REP(j,1,x){
                road[i][j]=true;
            }
        }
        
        cin >> n;
    
        REP2(i,0,n){
            
            cin >> c >> d;
            
            road[d][c] = false;
            if(c==0 && d==0)break;

        }
        
        solve(1,1);
    
        cout << ans << endl;
        
    }
    
    return 0;
}

int solve(int a,int b)
{
    if(x == a && y == b)ans++;
    
    for(int i=0; i < 2; i++){
        
        int tempa = a + dx[i];
        int tempb = b + dy[i];
        
        if(tempa <= x && tempb <= y && road[tempb][tempa] == true )
            solve(tempa, tempb);
    }
}
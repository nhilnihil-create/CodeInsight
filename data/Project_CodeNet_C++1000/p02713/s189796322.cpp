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
int gcd (int a,int b){
    if(b==0)return a;
    else return gcd(b,a%b);
}
int gcd3(int a,int b,int c){
    int g = 0;
    g = gcd(a,b);
    g = gcd(g,c);
    return g;
}
int K;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>K;
    int ans =0;
    REP(i,1,K+1){
        REP(j,1,K+1){
            REP(k,1,K+1){
                ans += gcd3(i,j,k);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

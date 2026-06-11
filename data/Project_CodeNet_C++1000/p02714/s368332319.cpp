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
int N;
string S;
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>N>>S;
    int r=0,g=0,b=0;
    rep(i,S.size()){
        if(S[i]=='R')r++;
        else if(S[i]=='G')g++;
        else b++;
    }
    int ans = r*g*b;
    rep(i,S.size()){
        for(int j = i;j<S.size();j++){
            int k = 2*j -i;
            if(k>=S.size())continue;
            if(S[i]!=S[j] && S[i]!=S[k]&&S[j]!=S[k]){
               // cout << i<<" "<<j<<" "<<k << endl;
                ans--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}

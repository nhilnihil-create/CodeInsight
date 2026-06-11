#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
#include <iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=999999999999;
ll dp[1<<20];

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    vector<vector<int> > c(m);

    for(int i=0;i<m;i++){
        int A,b;
        cin>>A>>b;
        a[i]=A;
        for(int j=0;j<b;j++){
            int _; cin>>_;
            _--;
            c[i].push_back(_);
        }
    }

    queue<int> q;
    q.push(0);
    for(int i=0;i<1<<n;i++) dp[i]=INF;
    dp[0]=0;

    while(!q.empty()){
        int bit=q.front(); q.pop();
        for(int i=0;i<m;i++){
            int nbit=0;
            for(int j:c[i]){
                nbit+=1<<j;
            }
            if(bit==(bit|nbit)) continue;
            nbit=bit|nbit;
            if(dp[nbit]>dp[bit]+a[i]){
                dp[nbit]=dp[bit]+a[i];
                q.push(nbit);
            }
        }
    }
    if(dp[(1<<n)-1]==INF){
        cout<<-1<<endl;
    }else{
        cout<<dp[(1<<n)-1]<<endl;
    }

}
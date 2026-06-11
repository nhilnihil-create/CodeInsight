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
typedef pair<ll,ll> P;
typedef pair<P,P> PP;
const ll MOD=1000000007;
const ll MAX_N=500010;
const ll INF=4999999996000000001;


int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int> > G(n);
    vector<bool> visited(n,false);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    queue<int> q;
    q.push(0);
    ll ans=k;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        visited[now]=true;
        int minu;
        if(now==0){
            minu=1;
        }else{
            minu=2;
        }
        for(int to:G[now]){
            if(visited[to]) continue;
            ans*=k-minu;
            ans%=MOD;
            q.push(to);
            minu++;
        }
    }
    cout<<ans<<endl;
}
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
const ll INF=1<<18;
vector<vector<int> > G(200100);
vector<int> cnt(200100,0);
vector<bool> done(200100,false);

void dfs(int c, int u){
    cnt[u]+=c;
    done[u]=true;
    //cout<<"debug"<<endl;
    for(int v:G[u]){
        if(!done[v]){
            dfs(cnt[u],v);
        }
    }
    return;
}

int main(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0;i<q;i++){
        int p,x;
        cin>>p>>x;
        p--;
        cnt[p]+=x;
    }
    dfs(0,0);
    for(int i=0;i<n;i++){
        cout<<cnt[i]<<" ";
    }
    cout<<endl;

}
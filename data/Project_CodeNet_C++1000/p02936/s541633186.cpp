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

int main(){
    int n,q;
    cin>>n>>q;
    vector<vector<int> > G(n);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> count(n,0);
    for(int i=0;i<q;i++){
        int p,x;
        cin>>p>>x;
        p--;
        count[p]+=x;
    }
    vector<bool> done(n,false);
    queue<int> Q;
    Q.push(0);
    while(!Q.empty()){
        int u=Q.front(); Q.pop();
        done[u]=true;
        for(int v:G[u]){
            if(!done[v]){
                count[v]+=count[u];
                Q.push(v);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<count[i]<<" ";
    }
    cout<<endl;

}
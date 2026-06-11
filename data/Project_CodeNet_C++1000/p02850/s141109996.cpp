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
map<P,int> ans;

int main(){
    int n;
    cin>>n;
    vector<vector<int> > G(n);
    vector<int> a(n-1),b(n-1);
    for(int i=0;i<n-1;i++){
        cin>>a[i]>>b[i];
        a[i]--; b[i]--;
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }
    queue<P> q;
    vector<bool> used(n,false);

    q.push(P(0,0));
    int color=0;

    while(!q.empty()){
        int u=q.front().first; 
        int kinsi=q.front().second;  
        q.pop();
        used[u]=true;
        color=max(color,(int)G[u].size());

        int c=1;
        for(int v:G[u]){
            if(!used[v]){
                if(kinsi==c) c++;
                ans[P(u,v)]=c;
                q.push(P(v,c));
                c++;
            }
        }
    }

    cout<<color<<endl;

    for(int i=0;i<n-1;i++){
        cout<<ans[P(a[i],b[i])]<<endl;
    }

}
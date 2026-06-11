#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <set>
#include <map>
#include <iterator>
#include <stack>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <list>
#include <string>

using namespace std;

long long MOD = 1000000007;



int main()
{
    int n;
    cin >> n;
    
    vector< vector< int > > G(n);
    vector< pair< int,int > > vp;
     
    for (int i = 1;i < n;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        vp.push_back(make_pair(a,b));
    }
    
    int K = 0;
    for (int i = 0;i < n;i++){
        int l = (int)G[i].size();
        K = max(K,l);
    }
    
    map< pair< int,int > ,int > I;
    vector<int> cs(n,0);
    vector<int> used(n,0);
    queue<int> q;
    used[0] = 1;
    q.push(0);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        int cur = 1;
        for (int u:G[v]){
            if (used[u])  {continue;}
            if (cur == cs[v]) cur++;
            cs[u] = I[make_pair(u,v)] = I[make_pair(v,u)] = cur++;
            used[u] = 1;
            q.push(u);
        }
    }
    cout << K << endl;
    for (pair<int,int> p:vp){
        cout << I[p] << endl;
    }
}

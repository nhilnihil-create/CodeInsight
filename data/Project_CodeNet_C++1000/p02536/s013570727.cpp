
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long  ll;


int f[100005];
int rk[1000005];
int find(int x){
    if(f[x]!=x) f[x]=find(f[x]);
    return f[x];
}



int main(int argc, const char * argv[]) {
    
    
    for(int i=1;i<=100000;i++) {f[i]=i;};
    
    int n,m;cin>>n>>m;
    int cnt=0;
    while (m--) {
        int u,v;cin>>u>>v;
        u=find(u);
        v=find(v);
        if(u==v) continue;
        f[u]=v;
        cnt++;
    }
    cout<<n-1-cnt<<endl;
    
    
    


    
    
   
    
    
    
     
    return 0;
}



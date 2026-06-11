#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <stdlib.h>
using namespace std;

#define INF 1e18
#define PI 3.141592653589793238
typedef long long ll;
#define N 100010

int main() {
    int n,m,h[N],ma[N];cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>h[i];
        ma[i]=0;
    }
    for(int i=0; i<m; i++){
        int a,b;cin>>a>>b;
        ma[a]=max(ma[a], h[b]);
        ma[b]=max(ma[b], h[a]);
    }
    int ans=0;
    for(int i=1; i<=n; i++){
        if(h[i]>ma[i]) ans++;
    }
    cout<<ans<<endl;


    return 0;
}
#include <bits/stdc++.h>
using namespace std;int main(){long N,O,u,v;cin>>N;O=N*(N+1)*(N+2)/6;
for(int i=1;i<N;i++){cin>>u>>v;O=O-min(u,v)*(N-max(u,v)+1);}
cout<<O;}

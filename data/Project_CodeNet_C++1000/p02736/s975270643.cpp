#include<bits/stdc++.h>
using namespace std;int N,i,v,k;char c;main(){for(cin>>N;i<N;cin>>c,v+=!(N-1&i^i)*--c,k|=c,i++);cout<<(v&1?1:k&1?0:v&3);}
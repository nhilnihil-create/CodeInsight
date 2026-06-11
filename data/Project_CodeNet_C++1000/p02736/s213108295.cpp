#include<bits/stdc++.h>
int N,i,v,k;char c;main(){for(std::cin>>N,i=N;i--;std::cin>>c,v+=!(N-1&i^i)*--c,k|=c);std::cout<<(v&1?1:v&2-(k&1));}
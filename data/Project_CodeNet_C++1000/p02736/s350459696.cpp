#include<bits/stdc++.h>
int N,i,v,k;char c;main(){for(std::cin>>N;N--;std::cin>>c,v^=!(N&i++)*c,k|=--c&1);std::cout<<(v&1?1:v&2-k);}
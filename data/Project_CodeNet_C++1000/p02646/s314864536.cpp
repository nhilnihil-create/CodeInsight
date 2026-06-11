#include <bits/stdc++.h>
int main(){int64_t a,v,b,w,t;std::cin>>a>>v>>b>>w>>t;
std::cout<<(v>w&&(v-w)*t>=abs(a-b)?"YES":"NO")<<'\n';}
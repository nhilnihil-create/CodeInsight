#include<bits/stdc++.h>
int n,j;main(){std::cin>>n;for(;n;n--){for(j=1;j<n;j++)std::cout<<(j>1?" ":"")<<(int)log2(j&-j)+1;std::cout<<"\n";}}
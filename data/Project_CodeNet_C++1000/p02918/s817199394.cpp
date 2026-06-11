#include <iostream>
int main(){int n,k;std::string s;std::cin>>n>>k>>s;int u=n-1;for(int i=1;i<n;i++)if(s[i]!=s[i-1])u--;std::cout<<std::min(n-1,u+2*k);}

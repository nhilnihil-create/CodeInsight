#include<iostream>
#include<string>
main(){int e;while(std::cin>>e&&e){int m=1<<30;for(int z=0,c=0;c<=e;++z,c=z*z*z)for(int y=0,b=0;c+b<=e;++y,b=y*y)m=std::min(m,e-c-b+y+z);std::cout<<m<<'\n';}}
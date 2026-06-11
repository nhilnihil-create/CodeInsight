#include <iostream>
int s,e;int main(){while(s*e<81)s+=(e=e%9+1)<2,std::cout<<s<<'x'<<e<<'='<<s*e<<'\n';return 0;}
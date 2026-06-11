#include <iostream>
int s,e;int main(){while((s+=(e=e%9+1)<2)<10)std::cout<<s<<'x'<<e<<'='<<s*e<<'\n';0;}
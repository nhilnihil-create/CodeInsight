#include<bits/stdc++.h>
int main(){
    int64_t a,b,x;
    std::cin>>a>>b>>x;
    if(x>=b)x=b-1;
    std::cout<<a*x/b<<'\n';
}
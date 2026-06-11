#include<bits/stdc++.h>
int main(){long double a,b,x;std::cin>>a>>b>>x;std::cout<<std::fixed<<(b>2*x/(a*a)?atan(b/(2*x/(a*b)))*180/acos(-1):atan((b-x/(a*a))/(a/2))*180/acos(-1));}
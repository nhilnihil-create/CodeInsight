#include<stdio.h>
#include<iostream>
#include<string>
#include<memory>
#include<cmath>
#include<algorithm>
#include<vector>
double min_double(double a,double  b){
    if(a<b) return a;
    else return b;
}
void swap(int *x,int *y){
    int tmp;
    tmp=*x;
    *x=*y;  
    *y=tmp;
}
int gcd(int a,int b){
    if(a<b) swap(&a,&b);
    if(b<1) return -1;

    if(a%b==0) return b;
    return gcd(b,a%b);
}
int lcm(int a,int b){
    return a * b / gcd(a,b);
}

int main(){
    int numQ;
    std::cin>>numQ;

    std::vector<int> d(numQ);
    for(int i=0;i<numQ;i++) std::cin>>d[i];

    std::sort(d.begin(),d.end());

    int ans = d[numQ/2]-d[(numQ/2)-1];
    std::cout<<ans<<std::endl;
    return 0;
}


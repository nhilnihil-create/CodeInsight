#include<stdio.h>
#include<iostream>
#include<string>
#include<memory>
#include<cmath>
#include<algorithm>
#include<vector>
#include<unordered_map>
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
    int N;
    std::cin>>N;
    std::vector<int> B(N);
    for(int i=0;i<N-1;i++) std::cin>>B[i];
    long ans=B[0]+B[N-2];

    for(int i=0;i<N-2;i++) ans+=std::min(B[i],B[i+1]);
    std::cout<<ans<<std::endl;


    return 0;
}
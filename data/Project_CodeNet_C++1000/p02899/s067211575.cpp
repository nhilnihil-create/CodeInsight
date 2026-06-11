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
    std::vector<int> order(N);
    for(int i=1;i<=N;i++){
        int a;
        std::cin>>a;
        order[a-1]=i;
    }

    for(int i=0;i<N;i++) std::cout<<order[i]<<" ";
    std::cout<<std::endl;

    return 0;
}
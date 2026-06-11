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
    int N;
    std::cin>>N;
    std::vector<long> height(N);
    long max=0;
    for(int i=0;i<N;i++) {
        std::cin>>height[i];
        if(max-height[i]>1){
            std::cout<<"No"<<std::endl;
            return 0;
        }
        if(height[i]>max) max=height[i];
    }
/*
    if(N==1){
        std::cout<<"Yes"<<std::endl;
        return 0;
    }
    
    for(int i=0;i<N;i++){
        if(height[i+1]<height[i]){
            if(height[i]-height[i+1]==1)height[i]--;
            else{
                //std::cout<<i<<std::endl;
                std::cout<<"No"<<std::endl;
                return 0;
            }
        }
    }
    */
    std::cout<<"Yes"<<std::endl;

    return 0;
}


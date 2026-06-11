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
    int numP,K,numQ;
    std::cin>>numP>>K>>numQ;
    std::vector<int> player(numP);
    for(int i=0;i<numQ;i++){
        int A;
        std::cin>>A;
        player[A-1]++;
    }
    for(int i=0;i<numP;i++){
        if(K-(numQ-player[i])<=0) std::cout<<"No"<<std::endl;
        else std::cout<<"Yes"<<std::endl;
    }
    return 0;
}
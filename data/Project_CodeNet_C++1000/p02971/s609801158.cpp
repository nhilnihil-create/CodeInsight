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

    std::vector<int> A(N);
    for(int i=0;i<N;i++) std::cin>>A[i];
    std::vector<int> B(A);

    std::sort(A.begin(),A.end());
    for(int i=0;i<N;i++){
        if(B[i]==A[N-1]) std::cout<<A[N-2]<<std::endl;
        else std::cout<<A[N-1]<<std::endl;
    }
    

    return 0;
}
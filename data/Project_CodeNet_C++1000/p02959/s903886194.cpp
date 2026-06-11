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
    std::vector<int> A(N+1);
    long long sum=0;
    for(int i=0;i<N+1;i++) {
        std::cin>>A[i];
        sum+=A[i];
    }
    std::vector<int> B(N);
    for(int i=0;i<N;i++) {
        std::cin>>B[i];
        if(B[i]>=A[i]){
            B[i]-=A[i];
            A[i]=0;
            if(B[i]>=A[i+1]) A[i+1]=0;
            else             A[i+1]-=B[i];
        }
        else A[i]-=B[i];
    }
    long long rest=0;
    for(int i=0;i<N+1;i++) rest+=A[i];

    long long ans=sum-rest;
    std::cout<<ans<<std::endl;

    

    return 0;
}


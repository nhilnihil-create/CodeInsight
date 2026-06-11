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
    std::vector<double> v(N);
    for(int i=0;i<N;i++) std::cin>>v[i];
    std::sort(v.begin(),v.end());
    for(int i=0;i<N-1;i++){
        v[0]=(v[0]+v[1])/2;
        v.erase(v.begin()+1);
    }
    std::cout<<v[0]<<std::endl;
    return 0;
}
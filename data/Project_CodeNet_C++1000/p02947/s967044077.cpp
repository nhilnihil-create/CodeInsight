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
    std::unordered_map<std::string,long> map;
    int N;
    long ans=0;
    std::cin>>N;
    std::string str;
    for(int i=0;i<N;i++){
        std::cin>>str;
        std::sort(str.begin(),str.end());
        //std::cout<<str<<std::endl;
        auto itr=map.find(str);
        if(itr!=map.end()){
            ans+=map[str];
            map[str]++;
        }
        else map[str]=1;
    }

    std::cout<<ans<<std::endl;
    return 0;
}
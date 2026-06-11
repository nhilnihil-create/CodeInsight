#include<stdio.h>
#include<iostream>
#include<string>
#include<memory>
#include<cmath>
#include<algorithm>
#include<vector>
double min(double a,double  b){
    if(a<b) return a;
    else return b;
}
int main(){
    double W,H,x,y;
    std::cin>>W>>H>>x>>y;

    double midX,midY;
    midX=W/2;
    midY=H/2;

    double ans=0;
    int judge=0;

    if(midX == x && midY == y) {
        ans = W * H / 2;
        judge = 1;
    }
    else{
        ans = W * H / 2;
    }
    
    printf("%.6f",ans);
    std::cout<<" "<<judge<<std::endl;

    return 0;
}


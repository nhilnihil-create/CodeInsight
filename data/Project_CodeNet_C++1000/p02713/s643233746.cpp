#include<iostream>

int gcd(int a,int b){
    int c=1;
    if(a<b){
        c=a;a=b;b=c;
    }
    while(c!=0){
        c=a%b;
        a=b;
        b=c;
    }
   return a;
}


int main(){
    
    int k,x=0;
    std::cin>>k;
    for(int s=1;s<=k;s++)
        for(int t=1;t<=k;t++)
            for(int u=1;u<=k;u++){
                x=x+gcd(gcd(s,t),u);
            }
    std::cout<<x<<std::endl;
}


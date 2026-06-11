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

int main()
{
    int k,ans=0;
    std::cin >> k;
    for(int i = 1; i <= k; i++)
        for(int j=1; j <= k; j++)
            for(int n=1; n <= k; n++){
                ans+=gcd(gcd(i,j),n);
            }
    std::cout << ans << std::endl;
}
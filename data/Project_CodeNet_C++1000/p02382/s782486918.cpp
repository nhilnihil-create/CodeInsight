#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
int main()
{
    int n;
    double pone=0;
    double ptwo=0;
    double pthree=0;
    double pfour=0;
    std::cin >> n;
    int lista[n]={0};
    int listb[n]={0};
    for(int i=0;i<n;i++){
        std::cin >> lista[i];
    }
    for(int j=0;j<n;j++){
        std::cin >> listb[j];
    }
    for(int k=0;k<n;k++){
        pone+=abs(lista[k]-listb[k]);
        ptwo+=abs(lista[k]-listb[k])*abs(lista[k]-listb[k]);
        pthree+=abs(lista[k]-listb[k])*abs(lista[k]-listb[k])*abs(lista[k]-listb[k]);
        if(pfour<abs(lista[k]-listb[k]))pfour=abs(lista[k]-listb[k]);
    }
    ptwo=sqrt(ptwo);
    pthree=cbrt(pthree);
    printf("%.8f\n",pone);
    printf("%.8f\n",ptwo);
    printf("%.8f\n",pthree);
    printf("%.8f\n",pfour);
 //   std::cout << pone << " " << ptwo << " " << pthree << " " << pfour << std::endl;
    return 0;
}
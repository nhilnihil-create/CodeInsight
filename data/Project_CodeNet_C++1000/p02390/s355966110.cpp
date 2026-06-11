#include <cstdio>
#include <iostream>

using namespace std;

main(){
       long int n,jam,menit;
       scanf("%ld",&n);
       jam = n / 3600;
       n = n % 3600;
       menit = n / 60;
       n = n % 60;
       printf("%ld:%ld:%ld\n",jam,menit,n);

       return 0;
       }
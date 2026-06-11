#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int main(){
    int n;
    double s[1000];
    double sum=0;
    double sum2=0;
    int i;
    double m;
    double m2;
    double m3;
    
    for(;;){
        sum=0;
        m=0;
        sum2 = 0;
        m3 = 0;
        cin >> n;
        if (n==0)break;
        for ( i = 0;i < n; i++ ){
            cin >> s[i];
            sum = sum + s[i];
        }
            m=sum / n;
            
        for  ( i = 0;i < n; i++ ){
           sum2 = sum2 + ((s[i] - m) * (s[i] - m));        
        }
        m3 = sqrt(sum2 / n);

        printf("%-20.8f\n",m3);
    }
    
    return 0;
}
#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int main(){
    int n;
    int x[100];
    int y[100];
    double p1 = 0;
    double p2 = 0;
    double p3 = 0;
    double pInf = 0;
    int absDiff = 0;
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];
    
    for (int i = 0; i < n; i++) {
        absDiff = abs(x[i]-y[i]);
        p1 += absDiff;
        p2 += absDiff * absDiff;
        p3 += absDiff * absDiff * absDiff;
        if(pInf < absDiff) pInf = absDiff; 
    }
        
     printf("%lf\n",p1);
     printf("%lf\n",sqrt(p2));
     printf("%lf\n",cbrt(p3));
     printf("%lf\n",pInf);
        
       
            
    
    
   
    return 0;
}
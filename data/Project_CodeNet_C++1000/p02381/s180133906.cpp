#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
    int n;
    while(1){
        double l=0,s=0;
        double a=0,c=0,b=0,m=0;
        cin>>n;
        double S[n]={};
        if(n==0){
            break;
        }
        else{
            for(int i=0;i<n;i++){
                cin>>S[i];
                l+=S[i];
            }
            m = l/n;
            for(int k=0;k<n;k++){
                a+=(m-S[k])*(m-S[k])/n;
            }
                printf("%.8lf\n", sqrt(a)); 
        }
    }
return 0;
}

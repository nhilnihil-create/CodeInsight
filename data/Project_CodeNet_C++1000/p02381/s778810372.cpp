#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int main(){
    int n,A[1000],sum;
    double ave,sum1;
    while(1){
        cin >> n;
        if(n==0) break;
        sum = 0;
        for(int i=0;i<n;i++){
            cin >> A[i];
            sum += A[i];
        } 
        ave = 1.0*sum/n;
        sum1 = 0.0;
        for(int i=0;i<n;i++){
            sum1 += pow((ave-A[i]),2);
        }
        printf("%.5f\n",sqrt(sum1/n));
    }
    return 0;
}

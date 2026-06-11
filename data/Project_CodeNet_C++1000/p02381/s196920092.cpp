#include<iostream>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;

int main(){
    int n;
    int S[1000];
    double sum = 0;
    double std = 0;
    double deviate = 0;
    while(1) {
        cin >> n;
        if (n == 0) break;
        for(int i = 0; i < n;i++) cin >> S[i];
        for(int i = 0; i < n; i++) {
            sum += S[i]; 
        }
        for (int i = 0; i < n; i++) {
            deviate += (S[i] - sum/n) * (S[i] - sum/n);  
        }
        
        printf("%lf\n",sqrt(deviate/n));
        sum = 0;
        std = 0;
        deviate = 0;    
    }
    
   
    return 0;
}
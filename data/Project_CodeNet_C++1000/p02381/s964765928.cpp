#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
    int n;
    int s[1000];
    double a,b,sum,ave;
    
    
    while(true){
        a = b = ave = sum = 0;
        
        cin >> n;
        
        if(!n) break;
        
        for(int i = 0; i < n; i++){
            cin >> s[i];
            sum += s[i];
        }
        
        ave = sum / n;
        
        for(int i = 0; i < n; i++){
            a += (s[i]-ave)*(s[i]-ave)/(double)n;
        }
        
        b = sqrt(a); 
        printf("%f\n",b);
    }
    return 0;
}
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
 
int main(){
    int n;
    int pt[1000];
    double s, s2, sum, avg;
     
     
    while(1){
        s = s2 = avg = sum = 0;
         
        cin >> n;
         
        if(n == 0) break;
         
        for(int i=0; i<n; i++){
            cin >> pt[i];
            sum += pt[i];
        }
         
        avg = sum / n;
         
        for(int i=0; i<n; i++){
            s2 += (pt[i]-avg)*(pt[i]-avg)/(double)n;
        }
         
        s = sqrt(s2); 
        printf("%f\n",s);
    }
    return 0;
}


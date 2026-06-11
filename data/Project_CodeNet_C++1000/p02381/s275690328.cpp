#include <iostream>
#include <math.h>

using namespace std;
int main(void){
    int n;
    
    while(1){
        cin >> n;
        
        if(n==0) break;
        
        int s[n];
        
        double ave=0;
        for(int i=0;i<n;i++){
            cin >> s[i];
            ave += s[i];
        }
        ave = ave/n;
        double var=0;
        for(int i=0;i<n;i++){
            var += pow(ave-s[i],2);
        }
        var=var/n;
        
        cout << fixed << sqrt(var) << endl;
    }
}


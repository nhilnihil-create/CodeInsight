#include <iostream>
#include <cmath>

using namespace std;

int main(){
        
    int i, n;
    double ave, sd, sum;
    double * S;
    
    while(1){
        cin >> n;
        if(n == 0){break;}
  
        S = new double [n];
        
        sum = 0;
        for(i = 0; i < n; i++){
            cin >> S[i];
            sum += S[i];
        }
            
        ave = (double) sum / (n);
        sum = 0;
        
        for(i = 0; i < n; i++){
            sum += pow(S[i] - ave, 2);
        }
        
        sd = sqrt(sum / n);
        cout << fixed << sd << endl;
        delete[] S;
    }
}
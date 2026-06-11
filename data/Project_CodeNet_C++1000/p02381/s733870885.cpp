#include <iostream>
#include <cmath>
using namespace std;

int main(){
    
    while(1){
        double n,var = 0.0,sd;
        double num[1000];
        double ave = 0.0;
        cin >> n;
        if(n == 0) break;
        
        for(int i = 0; i < n; ++i){
            cin >> num[i];
            ave += num[i];
        }
        ave = ave / n;
        for(int i = 0; i < n; ++i){
            var += (num[i] - ave) * (num[i] - ave);
        }
        var = var / n;
        sd = sqrt(var);
        cout << sd << endl;    
    }
    
    return 0;
}
#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    // Your code here!
    while(1){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        
        int s[n];
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }
        
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += s[i];
        }
        
        double m = (double)sum / n;
        double sum2 = 0;
        for(int i = 0; i < n; i++){
            sum2 += pow(s[i] - m, 2);
        }
        
        cout << sqrt(sum2 / n) << endl;
    }
}


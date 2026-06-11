#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

#define MAX_STUDENTS 100
using namespace std;
int main(void){
    int n;
    int i;
    int tmp;
    int sum, sq_sum;
    double mean, sq_mean;
    double std_dev;
    
    while(true){
        cin >> n;
        if(!n) break;
        sum = 0;
        sq_sum = 0;
        for(i = 0; i < n; i++){
            cin >> tmp;
            sum += tmp;
            sq_sum += tmp*tmp;
        }
        mean = static_cast<double>(sum) / n;
        sq_mean = static_cast<double>(sq_sum) / n;
        
        std_dev = sqrt(sq_mean - mean*mean);
        cout << fixed << std_dev << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;


int main() {
    
    while (1) {
        double n = 0;
        double sum = 0, sum2 = 0;
        double average = 0.0;
        double output = 0.0;
        cin >> n;
        
        if (n == 0) break;
        
        vector<double> array, array2;
        
        for (int i = 0; i < n; ++i) {
            int score;
            cin >> score;
            array.push_back(score);
            sum += array[i];
        }
        
        average = sum / n;
        
        for (int i = 0; i < n; ++i) {
            double diff = array[i] - average;
            array2.push_back(pow(diff, 2.0));
            sum2 += array2[i];
        }
        
        output = sqrt(sum2 / n);
        
        cout << output << "\n";
        //printf("%f\n", output);
    }
    return 0;
}
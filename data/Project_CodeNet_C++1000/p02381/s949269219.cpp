#include<iostream>
#include <math.h>
#include <iomanip>

using namespace std;
int main(){
    int n, grades;
    cin >> n;
    while (n!= 0) {
        int array[n] = {};
        double sum = 0;
        double othersum = 0;
        for (int i = 0; i < n; i++) {
            cin >> grades;
            sum += grades;
            array[i] = grades;
        } double average = sum / n;
        for (int i = 0; i < n; i++) {
            othersum += pow(array[i] - average, 2) / n;
        }
        othersum = sqrt(othersum);
        cout <<fixed << setprecision(10) << othersum << endl;
        cin >> n;
    }

    }

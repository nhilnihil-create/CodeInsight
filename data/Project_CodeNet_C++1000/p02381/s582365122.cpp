#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
int main(void){
    int num;
    while(1){
        cin >> num;
        if(num == 0) break;
        double points[num];
        double mean = 0, sd = 0;
        for(int i=0; i<num; i++){
            cin >> points[i];
            mean += points[i];
        }
        mean /= num;
        for(int i=0; i<num; i++){
            sd += pow((points[i] - mean), 2);
        }
        sd /= num;
        sd = sqrt(sd);
        printf("%.8lf\n", sd);
    }
    return 0;
}
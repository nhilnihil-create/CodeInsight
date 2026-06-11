#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <queue>
 
using namespace std;
 
int s[1000];
 
int main(void){
    while (true){
        int n;
        double ave, temp = 0, ans = 0, sum = 0;
        scanf("%d", &n);
        if (n == 0) break;
        for (int i = 0; i < n; i++){
            scanf("%d", &s[i]);
            sum = sum + s[i];
        }
        ave = sum / n;
        for (int i = 0; i < n; i++){
            temp += (s[i] - ave)*(s[i] - ave);
        }
        ans = sqrt(temp / n);
        printf("%f\n", ans);
    }
}
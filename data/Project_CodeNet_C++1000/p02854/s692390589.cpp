#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long int N;
    cin >> N;
    long long int bars[N];
    
    long long int x;
    long long int total = 0;
    for (int i =0; i < N; i++) {
        cin >> x;
        total += x;
        bars[i] = x;
    }
    
    long long int r_total = 0;
    long long int min;
    for (int i = 0; i < N - 1; i++) {
        r_total += bars[i];

        if ((total - r_total) == r_total) {
            cout << "0" << endl;
            return 0;
        }
        if (i == 0)
            min = abs((total - r_total) - r_total);
        else
            if (min > abs((total - r_total) - r_total))
                min = abs((total - r_total) - r_total);
    }
    
    cout << min << endl;
    
    return 0;
}
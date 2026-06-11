#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define ll         long long
#define PI         acos(-1.0)
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)

int main(){
    while(1){
        double n;
        vector<double> s(1000, 0);
        cin >> n;
        if(n==0) break;
        double sum = 0;
        FOR(i, 0, n){
            cin >> s[i];
            sum += s[i];
        }
        double m = sum / n;
        double sigma = 0;
        FOR(i, 0, n) sigma += pow((s[i] - m), 2);
        sigma /= n;
        sigma = sqrt(sigma);
        printf("%.05lf\n", sigma);
    }
}
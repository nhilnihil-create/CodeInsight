#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    long long n, d;
    cin >> n >> d;

    long long x[n][d];

    for(long long i = 0; i < n; i++){
        for(long long j = 0; j < d; j++){
            cin >> x[i][j];
        }
    }

    long long count = 0;
    for(long long i1 = 0; i1 < n; i1++){
        for(long long i2 = i1+1; i2 < n; i2++){
            long long distance = 0;
            for(long long j = 0; j < d; j++){
                distance += (x[i1][j] - x[i2][j])*(x[i1][j] - x[i2][j]);
            }
            long long a = (long long)sqrt((double)distance);
            if(a*a == distance){
                count++;
            } 
        }
    }
    cout << count << endl;
    return 0;
}
#include <math.h>

#include <cmath>
#include <iostream>
using namespace std;
int main() {
    long long n,t=0;
    cin >> n;
    for (long long i = 0; i < n;i++){if(((i+1)%3)!=0&&((i+1)%5)!=0){
            t = t + i+1;
    }
    }
    cout << t << endl;
    return 0;
}
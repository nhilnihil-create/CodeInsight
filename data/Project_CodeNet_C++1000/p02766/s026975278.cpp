#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
const long long MAX = 1000000000;

int main(){
    long long n, k;
    cin>>n>>k;
    for (long long i=1;i<=MAX;i++){
        if (pow(k, i) > n){
            cout << i << endl;
            return 0;
        }
    }
}
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long h;
    cin >> h;

    long long double_factor = 1;
    long long sum = 0;

    while(1){
        if(double_factor > h){
            break;
        }  
        sum += double_factor;
        double_factor = double_factor * 2;
    }
    cout << sum << endl;
    return 0;
}
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main(){
    int N;
    cin >> N;

    double x = N / 1.08;
    int x_min = floor(x);
    int x_max = ceil(x);

    int x_tmp = x_min;
        
    while(x_tmp <= x_max){
        if (int(x_tmp*1.08)==N){
            cout << x_tmp << endl;
            return 0;
        }
        x_tmp += 1;
    }
    cout << ":(" << endl;
    return 0;

}
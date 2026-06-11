#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l, sum = 0, near_zero = 10000000;
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        int x = l + (i+1) - 1;
        sum += x;
        if(abs(near_zero) > abs(x)) near_zero = x;
    }
    cout << sum - near_zero << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, d;
    cin >> n >> d;

    int temp, ans;
    temp = 2*d + 1;
    
    if (n%temp == 0){
        cout << n/temp << endl;
    }
    else{
        cout << n/temp + 1 << endl;
    }
    return 0;
}
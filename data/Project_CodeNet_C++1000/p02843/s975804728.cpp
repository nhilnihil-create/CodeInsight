#include <bits/stdc++.h>
using namespace std;
int main(){
    long x;
    cin >> x;
    long num = 1;
    while(num<=1000000){
        if((100*num<=x)&&(x<=105*num)){
            cout << 1 << endl;
            return 0;
        }
        num++;
    }
    cout << 0 << endl;
    return 0;
}
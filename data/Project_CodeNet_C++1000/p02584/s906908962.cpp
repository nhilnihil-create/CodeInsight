#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int x, k, d;
    cin >> x >> k >> d;
    x = abs(x);
    
    long long int mini = min(k, x/d);
    k -= mini;
    x -= mini * (d);
    
    if(k%2 == 0){
        cout << x << endl;
    }
    else{
        cout << d-x << endl;
    }
}

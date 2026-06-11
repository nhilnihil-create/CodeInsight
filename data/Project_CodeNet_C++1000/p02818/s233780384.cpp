#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int a, b, k;
    cin >> a >> b >> k;

    if(k >= a){
      k = k-a;
      a = 0;
    }
    else if(a > k){
        a = a-k;
        cout << a << " " << b;
        return 0;
    }
    if(k >= b){
        b = 0;
        cout << a << " " << b;
    }
    else if (b > k){
        b = b-k;
        cout << a << " " << b;
    }
}
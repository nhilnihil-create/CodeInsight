#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int a, b;
    cin >> a >> b;
    int k1;
    k1 = a + b;
    if(k1 % 2 != 0){
        cout << "IMPOSSIBLE\n";
    }
    else{
        cout << k1/2 << "\n";
    }
}
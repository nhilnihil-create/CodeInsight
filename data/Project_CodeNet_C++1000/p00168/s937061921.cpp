#include <bits/stdc++.h>
using namespace std;

long long calc(int x){
    if(x < 0) return 0;
    if(x == 0) return 1;
    return calc(x - 1) + calc(x - 2) + calc(x - 3);
}

int main(){
    long long n;
    while(cin >> n, n){
        cout << (calc(n) + 3649) / 3650  << endl;
    }
}
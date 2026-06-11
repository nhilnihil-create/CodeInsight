#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n; cin >> n;
    int c = sqrt(n);
    long long a = 0;
    for(int i=c; i>0; i--){
        if(n%i==0){
            a = i;
            break;
        }
    }
    long long b = n/a;
    cout << a + b -2 << endl;
}
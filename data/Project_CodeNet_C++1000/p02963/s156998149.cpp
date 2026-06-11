#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int s;
    cin >> s;
    long long int n=1000000000;
    cout << 0 << " " << 0 << " " << n << " " ;
    long long int a=(s+n-1)/n,b=-s+n*a;
    cout << b << " " << 1 << " " << a;
    cout << endl;
}
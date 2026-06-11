#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
int main(){
    long double a, b, c; cin >> a >> b >> c;
    long double eps = 1.0E-14;
    if(sqrt(a)+sqrt(b) +eps < sqrt(c)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
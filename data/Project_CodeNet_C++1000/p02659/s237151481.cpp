#include<bits/stdc++.h>
using namespace std;

int main(){
    long double a,b; cin >> a >> b;
    b = 100*b;
    cout << (long long int)(a*b/100 + 0.001) << endl;
}
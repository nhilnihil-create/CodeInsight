#include<bits/stdc++.h>
using namespace std;

int main(){
    long double a,b; cin >> a >> b;
    b = (long long int)(100*b + 0.001);
    cout << (long long int)(a*b/100) << endl;
}
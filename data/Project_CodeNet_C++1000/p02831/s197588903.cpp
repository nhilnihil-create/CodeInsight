#include<bits/stdc++.h>

using namespace std;
int main(){
    long a,b;
    cin >> a >> b;
    cout << (a*b)/__gcd(a,b) << endl;
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

long long int lcm(long long int a, long long int b){
    return (a *b) / __gcd(a, b);
}

int main(){
        long long int a, b, c, d; cin >> a >> b >> c >> d;
        a -= 1;
        long long int e = lcm(c, d);
        long long int r = (b / c) + (b / d) - (b / e);
        long long int l = a / c + a / d - a / e;
        long long int num = b - a;
        long long int div = r - l;
        num -= div;
        cout << num << endl;
    return 0;
}


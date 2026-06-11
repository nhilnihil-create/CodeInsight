#include <bits/stdc++.h>
using namespace std;

template <typename T>
T euqlid(T a, T b){
    if(a < b){
        int x = a;
        a = b;
        b = x;
    }
    T q, r;
    q = b;
    r = a % b;
    if(r) return euqlid(q, r);
    else return q;
}

int main(){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long new_b, new_a;
    a--;
    new_b = b / c + b / d - b / (c * d / euqlid(c,d));
    new_a = a / c + a / d - a / (c * d / euqlid(c,d));
    cout << (b - a) - (new_b - new_a) << endl;
    return 0;
}
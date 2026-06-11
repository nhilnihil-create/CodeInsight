#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    long a,b,c,d;
    cin >> a >> b >> c >> d;
    long e = c*d/gcd(c,d);
    a--;
    cout << b-b/c-b/d+b/e-(a-a/c-a/d+a/e) << endl;
}

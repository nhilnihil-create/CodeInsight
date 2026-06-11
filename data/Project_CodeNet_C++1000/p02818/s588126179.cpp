#include <bits/stdc++.h>
#define f(i, a, b) for(int i = a; i < (b); ++i)
#define rep(i,n) f(i, 0, n)
using namespace std;
using ll = long long;

int main(void){
    long int a, b ,k;
    cin >> a >> b >> k;
    if(a >= k){
        cout << a-k << ' ' << b << endl;
    }else if(a+b >= k){
        cout << "0 " << a + b - k << endl;
    }else{
        cout << "0 0" << endl;
    }
    return 0;
}
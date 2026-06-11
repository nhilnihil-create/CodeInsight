#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    i64 t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    i64 p = (a1 - b1)*t1, q = (a2 - b2)*t2;
    if(p > 0){
        p *= -1;
        q *= -1;
    }
    if(p+q < 0)cout << 0 << endl;
    else if(p+q == 0)cout << "infinity" << endl;
    else{
        if((-p)%(p+q) == 0)cout << 2*(-p/(p+q)) << endl;
        else cout << 2*(-p/(p+q))+1 << endl;
    }

    return 0;
}
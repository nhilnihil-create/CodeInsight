#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    i64 s;
    cin >> s;
    i64 x = (1000000000 - s%1000000000)%1000000000;
    i64 y = (s+x) / 1000000000;

    cout << "0 0 1000000000 1 " << x << " " << y << endl;

    return 0;
}
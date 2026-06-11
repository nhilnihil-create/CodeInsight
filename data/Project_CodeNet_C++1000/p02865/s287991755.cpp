#include<bits/stdc++.h>
using namespace std;

using i64 = int64_t;

int main(){
    int n;
    cin >> n;
    cout << (n/2 - !(n&1)) << endl;

    return 0;
}
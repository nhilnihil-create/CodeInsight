#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x, temp;
    cin >> x;

    temp = x / 100;
    cout << (temp * 105 >= x ? 1 : 0) << endl;
}
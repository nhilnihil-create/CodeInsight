#include <string>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
int main()
{
    long long n;
    int k;
    cin >> n >> k;
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    double ans = ceil(log(n) / log(k));
    cout << ans << endl;
}
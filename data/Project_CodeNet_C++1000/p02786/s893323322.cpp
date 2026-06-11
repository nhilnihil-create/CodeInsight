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
    long long h;
    cin >> h;
    long long logH = log(h) / log(2);
    long long ans = 0;
    for(int i = 0; i <= logH; i++){
        ans += pow(2, i);
    }
    cout << ans << endl;
}
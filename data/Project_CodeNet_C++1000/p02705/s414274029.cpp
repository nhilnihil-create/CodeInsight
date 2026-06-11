#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define GET_ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))
#define LL long long
LL facctorialMethod(int k);
int main(){
    double r;
    cin >> r;
    cout << (r+r)*M_PI << endl;

    return 0;
}

LL facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i){
        sum *= i;
    }
    return sum;
}

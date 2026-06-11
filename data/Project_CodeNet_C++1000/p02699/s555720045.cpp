#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define GET_ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))
#define LL long long
LL facctorialMethod(int k);
int main(){
//襲われる場合  ->unsafe
//襲われない場合->safe
    LL s,w;
    cin >> s >> w;
    if(s > w) cout << "safe" << endl;
    else cout << "unsafe" << endl;

    return 0;
}

LL facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i){
        sum *= i;
    }
    return sum;
}

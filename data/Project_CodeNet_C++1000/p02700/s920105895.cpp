#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define GET_ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))
#define LL long long
LL facctorialMethod(int k);
int main(){
    LL a,b,c,d;
    cin >> a >> b >> c >> d;
    while(a > 0 && c > 0){
        c = c - b;
        if(c <= 0) break;
        a = a - d;
//        cout << "a :" << a << endl;
//        cout << "c :" << c << endl;
    }

//        cout << "a :" << a << endl;
//        cout << "c :" << c << endl;

    if(c <= 0){
        cout << "Yes" << endl;
    } 
    else{
        cout << "No" << endl;
    } 

    return 0;
}

LL facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i){
        sum *= i;
    }
    return sum;
}

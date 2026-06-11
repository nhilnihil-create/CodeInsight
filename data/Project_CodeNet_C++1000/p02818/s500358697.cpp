#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define GET_ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))
#define LL long long
#define VI vector<int>
#define VL vector<LL>
#define VII vector< vector<int> >
#define VLL vector< vector<LL> >
#define VS vector<string>
#define PII pair<int,int>
#define PIS pair<int,string>
#define PSI pair<string,int>
#define PLL pair<ll,ll>
LL facctorialMethod(int k);
int main(){
    LL a,b,k,tmp;
    cin >> a >> b >> k;
    tmp = k;
    if(a <= k) {
        k = k - a;
        a = 0;        
        if(b <= k) {
            k = k - b;
            b = 0;
        }else{
            b = b - k;
        }
    }else{
        a = a -k;
    }
    cout << a << " " << b << endl;


    return 0;
}

LL facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i){
        sum *= i;
    }
    return sum;
}

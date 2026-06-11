#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define GET_ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))
#define LL long long
LL facctorialMethod(int k);
int main(){
    LL x,x_cnt,kin,ans;
    cin >> x;
    kin = 100;
    x_cnt = 0;

    while(kin < x){
//わからん
//        kin = floor(kin * 1.01);
        kin += kin / 100;
        x_cnt++;
//        cout << "kin :" << kin << endl;
//        cout << "x_xnt :" << x_cnt << endl;
    }

    ans = x_cnt;
    cout << ans << endl;

    return 0;
}

LL facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i){
        sum *= i;
    }
    return sum;
}

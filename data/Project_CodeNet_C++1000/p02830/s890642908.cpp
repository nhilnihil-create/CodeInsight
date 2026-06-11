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
    LL n;
    string s,t,ans;
    cin >> n;
    cin >> s >> t;
    for(int i = 0; i < n; i++) {
        ans += s[i];
        ans += t[i];
    }
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

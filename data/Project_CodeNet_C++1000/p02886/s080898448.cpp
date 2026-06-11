#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define GET_ARRAY_SIZE(a)   (sizeof(a)/sizeof(a[0]))
#define LL long long
#define VI vector<int>
#define VL vector<LL>
#define VII vector< vector<int> >
#define VLL vector< vector<LL> >
#define VS  vector<string>
#define VSS vector< vector<string> >
#define PII pair<int,int>
#define PIS pair<int,string>
#define PSI pair<string,int>
#define PLL pair<LL,LL>
const LL MOD = 1000000007;
const LL INF = 1e16;
LL facctorialMethod(int k);
int main(){
    LL n,s1,s2,total;
    cin >> n;
    VL d(n);
    s1 = 0, s2 = 0, total = 0;
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }

    for(int a = 0; a < n; a++) {
        for(int b = a+1; b < n; b++) {
            total += d[a] * d[b];
//            cout << "d[a] * d[b] : " << d[a] * d[b] << " total :" << total << endl;
        }
    }
    cout << total << endl;
    return 0;
}
/*
int main(){
    LL n,s1,s2,total;
    cin >> n;
    VL d(n);
    s1 = 0, s2 = 0, total = 0;
    for(int i = 0; i < n; i++) {
        cin >> d[i];
        s1 += d[i] * d[i];
        s2 += d[i];
        cout << "s1 :" << s1 << " s2 :" << s2 << endl;
    }
    total =  (s2 * s2 - s1) / 2;
    cout << total << endl;
    return 0;
}
*/

LL facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i){
        sum *= i;
    }
    return sum;
}

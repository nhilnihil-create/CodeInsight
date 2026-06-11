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
    LL n,s_len;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        s_len = s[i] - 'A';
        s_len = (s_len + n) % 26;
        s[i] = s_len + 'A'; 
//        cout << "s_len :" << s_len << endl;
    }
    cout << s << endl;

//    s_len = 'A';
//    cout << "s_len :" << s_len << endl;
    return 0;
}

LL facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i){
        sum *= i;
    }
    return sum;
}

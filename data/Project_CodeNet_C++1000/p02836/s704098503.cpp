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
    string s,s1,s2;
    LL s_len,count;
    cin >> s;
    s_len = s.size();
//    cout << s_len << endl;
    s1 = s.substr(0,s_len/2);
    s2 = s.substr(s_len-s_len/2,s_len/2);

//    s2 = reverse(s2.begin(), s2.end());
    reverse(s2.begin(), s2.end());

    count = 0;
    for(int i = 0; i < s_len/2; i++) {
//        cout << "s1.substr(i,1) :" << s1.substr(i,1) << endl;
        if(s1.substr(i,1) != s2.substr(i,1)) {
            count++;
        }
    }
    cout << count << endl;
    
    return 0;
}

LL facctorialMethod(int k){
    int sum = 1;
    for (int i = 1; i <= k; ++i){
        sum *= i;
    }
    return sum;
}

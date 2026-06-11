#include<iostream>
#include<string>

using namespace std;

long long two[100005];
long long three[100005];
long long MOD = 1000000007;

void init(){
    long long tw = 1;
    long long th = 1;
    for (int i=0;i<100005;i++) {
        two[i] = tw;
        three[i] = th;
        tw = (tw*2LL) % MOD;
        th = (th*3LL) % MOD;
    }
}

int main() {
    string s;
    cin>>s;
    init();
    int len = (int)s.size();
    int one = 0;
    long long ans = 0LL;
    for (int i=0;i<len;i++) {
        if (s[i] == '0') continue;
        long long tmp = two[one];
        tmp = (tmp * three[len - i - 1]) % MOD;
        ans = (ans + tmp) % MOD;
        one++;
    }
    ans = (ans + two[one]) % MOD;
    cout<<ans<<endl;
    return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef  long long ll;
typedef unsigned long long ull;

template<typename T>
void fin (T a){
    cout<<a<<endl;
    exit(0);
}
template<typename S>
void print(S a){
    cout<<a<<endl;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin>>s;
    int len=s.size();
    int ans =0;

    map<int,int> dp;
    int tmp;
    int mod=0;
    int powmod=1;
    rep(i,len) {
        tmp = s[len-1-i]-48;
        powmod = (powmod*10)%2019;
        mod = (ll)(tmp*powmod+mod)%2019;
        dp[mod]++;
    }

    for(auto x: dp){
        int a = x.second;
        if(x.first ==0){
            ans+= a;
        }
        ans += a*(a-1)/2;
    }

    fin(ans);
}

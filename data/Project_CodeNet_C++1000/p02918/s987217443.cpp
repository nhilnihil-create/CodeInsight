#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n, k;
string s;

int main(void){
    cin >> n >> k;
    cin >> s;
    s = 'R'+s+'L';
    lli ans = 0;
    for(int i = 1; i <= n; i++){
        if(s[i] == 'L'){
            if(s[i-1] == 'L') ans++;
        }else{
            if(s[i+1] == 'R') ans++;
        }
    }
    cout << min(ans+2*k, n-1) << endl;
    return 0;
}

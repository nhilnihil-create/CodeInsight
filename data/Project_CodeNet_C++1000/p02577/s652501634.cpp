#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    string s;
    cin >> s;
    int l=s.size();
    int sum=0;
    rep(i,l)sum+=s[i]-'0';
    cout << (sum%9==0?"Yes":"No");
}
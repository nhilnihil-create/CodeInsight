#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x ,n) for(int i = x; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main(){
    int n;
    string s;
    cin >> n >>  s;
    rep(i,s.size()){
        s[i]+=n;
        if(s[i]>'Z')s[i]-=26;
        cout << s[i];
    }
	return 0;
}
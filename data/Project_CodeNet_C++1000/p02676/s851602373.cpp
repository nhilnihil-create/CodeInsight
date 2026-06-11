#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli k;
string s;

int main(void){
    cin >> k >> s;
    if(s.size() <= k) cout << s << endl;
    else cout << s.substr(0, k)+"..." << endl;
    return 0;
}

#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
const long long mod = 10e9 + 7;

int main(){
    int n; cin>>n;
    string s; cin>>s;
    rep (i, s.size()){
        s[i] += n;
        if (s[i] > 'Z') s[i] -= 26;
    }
  cout << s;
}
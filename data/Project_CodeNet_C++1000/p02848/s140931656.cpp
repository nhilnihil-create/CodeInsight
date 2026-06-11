#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
using namespace std;

int main(){
    int n;
    cin>> n;
    string s;
    cin >> s;
    rep(i,s.size()){
        s[i]=(s[i]-'A'+n)%26 + 'A';
    }
    cout << s << endl;
    return 0;
}
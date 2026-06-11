#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    rep(i, s.size()){
        s[i]=s[i]+n;
        if(s[i]>'Z'){
            s[i] = s[i]-26;
        }
    }
    cout << s<< endl;
}
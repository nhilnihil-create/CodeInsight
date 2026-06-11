#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    vector<char> s(n);
    vector<char> t(n);
    rep(i,n){
        cin>>s[i];
    }
    rep(i,n){
        cin>>t[i];
    }
    rep(i,n){
        cout<<s[i]<<t[i];
    }
    cout<<endl;
}
#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    string ans{};
    rep(i, n){
        ans.push_back(s[i]);
        ans.push_back(t[i]);

    }
    cout<<ans<<endl;
}
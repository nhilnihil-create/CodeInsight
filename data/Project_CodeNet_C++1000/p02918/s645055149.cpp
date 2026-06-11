#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n,k;
    string s;
    cin>>n>>k>>s;
    int cnt=0;
    rep(i,n-1)if(s[i]!=s[i+1])cnt++;
    cout<<n-1-max(0,cnt-2*k)<<endl;
}
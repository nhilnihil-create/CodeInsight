#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    string t;
    cin>>t;
    int n=t.size();
    rep(i,n)if(t[i]=='?')t[i]='D';
    cout<<t<<endl;
    return 0;
}

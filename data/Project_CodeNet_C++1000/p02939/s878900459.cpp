#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int ans=n;
    rep(i,n){
        if(s[i]==s[i+1]){
            ans--;
            i+=2;
        }
    }
    cout<<ans<<endl;
}

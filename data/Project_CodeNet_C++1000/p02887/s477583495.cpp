#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main() {
    int n;
    cin>>n;
    int ans=n;
    vector<char> s(n);
    rep(i,n){
        cin>>s[i];
        if(i>0 && s[i]==s[i-1]){
            ans--;
        }
    }
    cout<<ans<<endl;
}
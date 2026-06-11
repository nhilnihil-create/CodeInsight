#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    vector<string>s;
    rep(i,n){
        string t;cin>>t;
        s.push_back(t);
    }
    sort(s.begin(),s.end());
    
    int tmp = 1;
    int m = 1;
    rep(i,n-1){
        if(s[i+1]==s[i])++tmp;
        else{
            m=max(m,tmp);
            tmp=1;
        }
    }
    m=max(m,tmp);
    tmp = 1;

    rep(i,n-1){
        if(s[i+1]==s[i])++tmp;
        else{
            if(tmp==m)cout<<s[i]<<endl;
            tmp=1;
        }
    }
    if(tmp==m)cout<<s[n-1]<<endl;
 	return 0;
}
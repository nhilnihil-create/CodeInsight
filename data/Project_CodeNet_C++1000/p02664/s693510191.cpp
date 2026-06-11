#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i < (int)n;++i)

int main() {
    string s;cin>>s;
    int n = s.size();
    rep(i,n){
        if(s[i]=='?'){
            if(i > 0 && s[i-1]=='P')s[i]='D';
            else if(i < n-1 && s[i+1]=='D')s[i]='P';
            else if(i < n-1 && s[i+1]=='?'){
                s[i]='P';
                s[i+1]='D';
            }
            else s[i]='D';
        }
    }
    cout<<s<<endl;
	return 0;
}

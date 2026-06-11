#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)n;++i)

int main() {
    int n;cin>>n;
    string s;cin>>s;
    int m = s.size();
    rep(i,m){
        s[i]+=n;
        if(s[i]<'A' || s[i]>'Z')s[i]-=26;
    }
    cout<<s<<endl;
	return 0;
}
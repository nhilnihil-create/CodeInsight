#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;
using ll=long long;
constexpr ll mod=1000000007;
constexpr int inf=1000000000;
constexpr ll linf=1000000000000000000;

int main(){
    string s,t;
    cin>>s>>t;
    bool flag=true;
    rep(i,s.size()){
        if(s[i]!=t[i])flag=false;
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

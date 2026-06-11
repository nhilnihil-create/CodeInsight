#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
using ll=long long;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    int ans=0;
    string ss;
    int cnt=0;
    for(int i=0;i<s.size();++i){
        if(s[i]=='R'){
            cnt++;
        }
    }
    for(int i=0;i<s.size();++i){
        if(i<cnt||cnt==s.size())ss.append("R");
        else ss.append("W");
    }
    int f=0,ff=0;
    for(int i=0;i<s.size();++i){
        if(s[i]!=ss[i]){
            if(i<cnt)f++;
            else ff++;
        }
    }
    if(f==ff)ans=f;
    else{
        ans=min(f,ff);
        ans+=abs(f-ff);
    }
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+233;

int t,n;
int main(){
    string s;
    cin>>s;
    long long ans=0;
    for(int i=0;i<s.size();i++){
        ans+=s[i]-'0';
        if(ans%9==0)ans=0;
    }
    if(ans%9==0)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
        return 0;
}

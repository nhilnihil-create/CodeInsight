#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+10;
const int mod=1e9+7;
int l=0;
main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s[0]=='W'||s[2*n-1]=='W'){
        puts("0");
        return 0;
    }
    l++;
    int ans=1;
    int sta=1;
    for(int i=1;s[i];++i){
        if(s[i]==s[i-1])
            sta^=1;
        if(sta)l++;
        else{
            if(l==0){
                puts("0");
                return 0;
            }
            ans=ans*l%mod;
            l--;
        }
    }
    if(l!=0){
        puts("0");
        return 0;
    }
    for(int i=1;i<=n;++i)ans=ans*i%mod;
    cout<<ans<<endl;
}

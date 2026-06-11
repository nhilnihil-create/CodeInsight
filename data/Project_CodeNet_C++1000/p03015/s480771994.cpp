#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int main(){
    string s;cin>>s;
    long long ans=0;
    int n=s.size(),cnt=0;
    vector<long long>a(n+1),b(n+1);
    a[0]=1;b[0]=1;
    for(int i=1;i<n+1;++i){
        a[i]=a[i-1]*3%MOD;
        b[i]=b[i-1]*2%MOD;
    }
    for(int i=0;i<n;++i){
        if(s[i]=='1'){
            cnt++;
            ans+=b[cnt-1]*a[n-i-1]%MOD;
            ans%=MOD;
        }
    }
    ans+=b[cnt];
    ans%=MOD;
    cout<<ans<<endl;
}
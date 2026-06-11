#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)s[i]-='0';
    long long x=0;
    if(k==2 || k==5){
        for(int i=0;i<n;i++)if(s[i]%k==0)x+=i+1;
        cout<<x<<endl;
        return 0;
    }
    long long p=1,wa=0;
    long long amari[k]={};
    amari[0]++;
    for(int i=n-1;i>=0;i--){
        wa=(wa+p*s[i])%k;
        amari[wa]++;
        p=p*10%k;
    }
    for(int i=0;i<k;i++)x+=amari[i]*(amari[i]-1)/2;
    cout<<x<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    string s,t;
    cin>>s>>t;
    ll i=0,ans=0;
    while(s[i]!='\0'){
        if(s[i]!=t[i])
            ans++;
        i++;
    }
    cout<<ans;
    return 0;
}

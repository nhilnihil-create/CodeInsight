#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
map<ll,ll> mp;
string s;
ll a[200001],tmp=1,ans;
int main(void){
    cin>>s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        a[i+1]=(s[i]-'0')*tmp;
        a[i+1]%=2019;
        tmp*=10;
        tmp%=2019;
    }
    for(int i=0;i<s.size();i++){
        a[i+1]+=a[i];
        a[i+1]%=2019;
        //cout<<a[i+1]<<endl;
        mp[a[i+1]]++;
    }
    mp[0]++;
    for(auto x:mp){
        ans+=x.second*(x.second-1)/2;
    }
    cout<<ans<<endl;
}

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

typedef long long ll;
using namespace std;

int main(){
    ll m=1e9+7,ans=0,l,t=1;
    string s;
    cin>>s;
    l=s.size();
    vector<ll> v(l);v[l-1]=1;
    for(int i=l-2;i>=0;i--) v[i]=(v[i+1]*3)%m;
    
    for(int i=0;i<l;i++){
        if(s[i]-'0') {
            ans+=v[i]*t;
            ans%=m;
            t<<=1;t%=m;
        }
    }
    ans+=t;
    cout<<ans%m;
}
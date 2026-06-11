#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ll sum=0;
    string s;
    cin>>s;
    for(ll i=0;i<s.size();i++){
        sum+=(s[i]-'0');
        sum%=9;
    }
    if(!(sum%9)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}

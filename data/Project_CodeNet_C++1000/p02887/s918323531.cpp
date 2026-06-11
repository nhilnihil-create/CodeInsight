#include<bits/stdc++.h>
#define ll      long long int
#define nl      '\n'
using namespace std;

int main(void){

    ll n,m,ans=0,cnt=0;

    //vector<ll>a(n+5);

    string s;
        cin>>n;
        cin>>s;

    for(ll i=1; i<=n; i++){
        if(s[i]!=s[i-1]) cnt++;
    }
    cout<<cnt;
}


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
string strd(int n){
    string x;
    while(n){
        int d=n%10;
        x+=(d+'0');
        n/=10;
    }
    reverse(x.begin(),x.end());
    return x;
}
void digit()
{
    cin>>s;
    ll sum=0;
    for(int i=0;i<s.size();i++){
        char a=(char)s[i];
        int d=(int) a-'0';
        sum+=d;
    }
    if(sum%9==0)cout<<"Yes\n";
    else cout<<"No\n";
}
int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll d=0;
    for(ll i=1;i<n;i++){
       if(a[i-1]>a[i]){
        d+=a[i-1]-a[i] ;
       /// cout<<a[i-1]<<' '<<a[i]<<endl;;
        a[i]=a[i-1];
       }
    }
    cout<<d<<endl;
}

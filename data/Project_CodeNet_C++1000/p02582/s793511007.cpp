#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  fi0 for(ll i=0;i<n;i++)
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
    string s;
    cin>>s;
    ll n=s.size()+1;
    int cnt=0,maxi=0;

    s+='S';
   /// cout<<s<<endl;
    fi0 {
        if(s[i]=='R')cnt++;
        else{
            maxi=max(cnt,maxi);
            cnt=0;
        }
    }
    cout<<maxi<<endl;
}

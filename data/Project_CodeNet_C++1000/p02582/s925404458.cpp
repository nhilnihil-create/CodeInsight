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
    string s;
    cin>>s;
    int cnt=0;
    if(s[1]=='R')cnt++;
    if(cnt)
    {
        if(s[0]=='R')cnt++;
        if(s[2]=='R')cnt++;
        cout<<cnt<<endl;
    }
    else if(s[0]=='R'||s[2]=='R')cout<<1<<endl;
    else cout<<0<<endl;
}

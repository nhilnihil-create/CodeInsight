#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    string s;
    cin>>s;
    ll sum=0;
    for(ll i=0;i<s.length();i++)
    {
        sum+=s[i]-'0';
    }
    if(sum%9==0){
        cout<<"Yes"<<endl;
    }
    else{
       cout<<"No"<<endl;
    }




}

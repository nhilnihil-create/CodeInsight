#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
ll mod=998244353;
int main()
{
    ll a;
    string b;
    cin>>a;
    cin>>b;
    ll first=b[0]-'0';
    ll second=((b[2]-'0')*10)+b[3]-'0';
    ll num=first*100+second;
    cout<<(a*num)/100<<endl;


    
}
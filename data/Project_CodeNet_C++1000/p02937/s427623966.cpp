#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s,t;
ll L,LL,tot;
vector<ll> a[26],v;
int main(void){
    cin>>s>>t;
    L=0;
    for(int i=0;i<s.size();i++){
        a[s[i]-'a'].push_back(i+1);
    }
    for(int i=0;i<t.size();i++){
        if(a[t[i]-'a'].size()==0){cout<<-1<<endl;return 0;}
        LL=upper_bound(a[t[i]-'a'].begin(),a[t[i]-'a'].end(),L)-a[t[i]-'a'].begin();
        if(LL==a[t[i]-'a'].size())L=a[t[i]-'a'][0];
        else L=a[t[i]-'a'][LL];
        v.push_back(L);
    }
    L=0;
    for(ll x:v){
        if(L==x)tot+=s.size();
        if(L<x)L=x;
        if(L>x){tot+=s.size();L=x;}
    }
    cout<<tot+L<<endl;
}

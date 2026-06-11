#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long const mod = (1e9)+7;

int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    if(a+b+c>= 22)
        cout<<"bust"<<"\n";
    else
        cout<<"win"<<"\n";
}
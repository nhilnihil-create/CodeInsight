#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll n,m,st,ok;
vector<ll> v;
int main(void){
    cin>>n>>m;
    string s;
    cin>>s;
    reverse(s.begin(),s.end());
    while(1){
        //cout<<st<<endl;
        if(st==n){
            ok=1;
            break;
        }
        for(int i=min(m,n-st);i>=1;i--){
            //cout<<s[st+i]<<"i"<<endl;
            if(s[st+i]=='0'){
                st+=i;
                v.push_back(i);
                break;
            }
            else if(i==1)ok=-1;
        }
        if(ok==-1)break;
    }
    reverse(v.begin(),v.end());
    if(ok==1){
        for(auto x:v)cout<<x<<" ";
        cout<<endl;
    }
    else cout<<-1<<endl;
}

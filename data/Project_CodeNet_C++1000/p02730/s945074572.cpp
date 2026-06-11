#include<bits/stdc++.h>
#define ll long long
#define rep1    for( i=0; i<n; i++)
using namespace std;

int main(){
    ll n,i,j;
    string s,t,u,uu,v,vv;
    cin>>s;
    t=s;
    reverse(s.begin(),s.end());
    if(s==t)
    {
        u=s.substr(0,(s.size()-1)/2);
        uu=u;
        reverse(u.begin(),u.end());
        v=s.substr((s.size()+3)/2-1,(s.size()-1)/2);
        vv=v;
        reverse(v.begin(),v.end());
        if(u==uu&&v==vv)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;

    }
        else
            cout<<"No"<<endl;
    return 0;
}




#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll n,i,ok=0;
    string s;
    cin>>n>>s;
    if(n%2==1){
        cout<<"No"<<endl;
        return 0;
    }
    for(i=0;i<n/2;i++){
        if(s[i]!=s[i+(n/2)]){
            ok= 1;
        }
    }
    if(ok){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
    return 0;
}

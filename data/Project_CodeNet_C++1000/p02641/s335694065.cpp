#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n,x,p;
    cin>>x>>n;
    map<int,int>mp;
    for(int i=0; i<n; i++){
        cin>>p;
        mp[p]++;
    }
    ll mn=x;
    while(1){
        if(mp[mn]==0){
            break;
        }
        mn++;
    }
    ll mn1=x;
    while(1){
        if(mp[mn1]==0){
            break;
        }
        mn1--;
    }
    ll res1=abs(x-mn);
    ll res2=abs(x-mn1);
    if(res1<res2)
        cout<<mn<<endl;
    else if(res2>res1)
        cout<<mn1<<endl;
    else
        cout<<min(mn,mn1)<<endl;

}

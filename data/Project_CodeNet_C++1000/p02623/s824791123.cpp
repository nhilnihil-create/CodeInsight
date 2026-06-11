#include<bits/stdc++.h>
using namespace std;

#define ll long long int

vector<ll>arr1,arr2;

ll bs(ll lower, ll upper, ll no){

    ll pos=-1;
    while(lower<=upper){
        ll mid=(lower+upper)/2;
        if(no-arr2[mid]>=0){
            pos=max(pos,mid);
        }
        if(arr2[mid]<no)
            lower=mid+1;
        else
            upper=mid-1;

    }
    return pos;
}

int main(){
    ll n,m,k,i,temp,prefix;
    prefix=0;
    cin>>n>>m>>k;
    for(i=0;i<n;i++){
        cin>>temp;
        arr1.push_back(prefix+temp);
        prefix=arr1[i];
    }
    prefix=0;
    for(i=0;i<m;i++){
        cin>>temp;
        arr2.push_back(prefix+temp);
        prefix=arr2[i];
    }
    ll ans=0;
    i=0;
    while(i<n){
        if(k-arr1[i]>=0)
            ans=max(ans,i+1);
        i++;
    }
    i=0;
    while(i<m){
        if(k-arr2[i]>=0)
            ans=max(ans,i+1);
        i++;
    }
    i=0;
    while(i<n){
        ll j=bs(0,m-1,k-arr1[i]);
        if(j>=0)
            ans=max(ans,i+j+2);
        i++;
    }
    cout<<ans;
}

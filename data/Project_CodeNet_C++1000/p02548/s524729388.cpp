//"BISMILLAHIR RAHMANIR RAHIM"
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const long long M = 1e9+7 ;
ll fact(ll x, ll y){
    ll f=1,i=1;
    while(i<=y){
        f=( (f%M) * (x%M) )%M;
        i++;
    }
    return f;
}
int main()
{
    ll n,i,cnt=0,x,y,j;
    cin>>n;
    for(i=1;i<n;i++){
       for(j=1;i*j<n;j++)
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}



#include<bits/stdc++.h>

using ll=long long;
using namespace std;

int main(){
    ll a,b,n;
    cin>>a>>b>>n;
    
    if(b>n)
        cout<<floor(a*n/b)<<endl;
    else
        cout<<floor(a*(b-1)/b)<<endl;
}
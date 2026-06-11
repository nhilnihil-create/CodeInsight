#include<bits/stdc++.h>
using namespace std; 
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define lli long long int
int main(){
    fast;
    lli x,k,d,ld=0;
    cin>>x>>k>>d;
    if(x<0)x=-x;
    if(k<=x/d)cout<<x-k*d;
    else{
        k-=x/d;
        if(k%2==0)cout<<x%d;
        else cout<<abs(x%d-d);
    }
}
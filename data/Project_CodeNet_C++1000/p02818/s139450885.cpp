#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a,b,k;
    cin>>a>>b>>k;
    if(k>a){
        k=k-a;a=0;
    }
    else{
        a=a-k;
        cout<<a<<" "<<b<<endl;
        return 0;
    }
    if(k>b){
        k=k-b;b=0;
    }
    else b=b-k;
    cout<<a<<" "<<b<<endl;
    return 0;
}

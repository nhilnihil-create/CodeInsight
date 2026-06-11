#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n,i,sum;

    cin>>n;
    sum=0;
    for(i=0;i<n;i++){
        ll a;
        cin>>a;
        sum^=a;
    }
    cout<<(sum==0 ?"Yes" : "No")<<endl;

return 0;
}

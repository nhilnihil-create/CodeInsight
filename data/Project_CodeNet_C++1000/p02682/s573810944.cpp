#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using p = pair<ll,ll>;
#define rep(i,k) for(ll i = 0; i<(ll)k;i++)

int main()
{
    int a,b,c,n;
    cin>>a>>b>>c>>n;
    if(n <= a){
        cout<<n<<endl;
    }
    else if(n <= a+b){
        cout<<a<<endl;
    }
    else{
        cout<<a- (n-a-b)<<endl;
    }

    return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    ll a,b,n;
    cin>>a>>b>>n;
    if(n<b)cout<<a*n/b<<endl;
    else{
        if(a>b)cout<<max(a*n/b-a*(n/b),a*(n-n%b-1)/b-a*((n-n%b-1)/b))<<endl;
        else cout<<a*(b-1)/b<<endl;
    }
    return 0;
}
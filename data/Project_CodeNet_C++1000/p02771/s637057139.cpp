#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;
typedef pair<ll,ll> P;


int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    if((a==b&&a!=c)||(a==c&&a!=b)||(b==c&&a!=b))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

    








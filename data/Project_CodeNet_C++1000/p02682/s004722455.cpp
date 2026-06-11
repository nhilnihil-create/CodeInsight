#include <bits/stdc++.h>
#define rep( i, n ) for (ll i = 0; i < ( ll )(n); i++)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int , int > P;
typedef tuple<int, int, int> T;



int main(){
    ll a,b,c,k;
    ll ans=0;
    cin>>a>>b>>c>>k;

    if(k<=a){
        ans=k;
    }
    else if(a+b>=k){
        ans=a;
    }
    else{
        ans=a-(k-a-b);
    }
    cout<<ans;
}
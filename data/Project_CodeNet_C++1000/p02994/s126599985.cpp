#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    ll k,s,sum=0;
    cin>>k>>s;
    vector<ll> aji;
    ll x=s;
    ll n=s;
    for(int i=0;i<k;i++){
        aji.push_back(x);
        sum+=x;
        if(abs(0-x)<abs(0-n)){
            n=x;
        }
        x++;
    }
    cout<<sum-n<<endl;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n) for(ll i=0;i<(n);i++)
#define For1(i,n) for(ll i=1;i<(n);i++)
#define MOD 1000000007
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
void calc(vector<vector<ll>> &vec){
    For1(i,9){
        ll pw=1;For(j,i)pw*=2;
        for(ll j=pw;j<pw*2;j++){
            for(ll k=0;k<pw;k++){
                vec.at(j).at(k)=i+1;
            }
        }
        for(ll j=pw+1;j<pw*2;j++){
            for(ll k=pw;k<j;k++){
                vec.at(j).at(k)=vec.at(j-pw).at(k-pw);
            }
        }
    }
}
int main(){
    ll n;cin>>n;
    vector<vector<ll>> vec(513,vector<ll> (513));
    vec.at(1).at(0)=1;
    calc(vec);
    For(i,n+1){
        for(ll j=i+1;j<n;j++){
            cout<<vec.at(j).at(i)<<" ";
        }
        cout<<endl;
    }
}

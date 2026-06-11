#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

typedef long long ll;


set<ll> yz;


bool f(ll x, ll y){
    while(x%y==0){
        x/=y;
    }
    return x%y==1;
}
int main(){
    ll n;
    cin>>n;
    if(n==2){
        cout<<1<<endl;
        return 0;
    }
    int S =0;
    for(int i = 2; i<=sqrt(n); i++ ){
        if(n%i==0) {
            if(f(n,i)) ++S;
        }
    }


    for(int i = 2; i<=sqrt(n-1); i++){
        if((n-1)%i==0){
            yz.insert(i);
            yz.insert((n-1)/i);
        }
    }
    int ans = S+yz.size();
    cout<<ans+2<<endl;
    return 0;

}
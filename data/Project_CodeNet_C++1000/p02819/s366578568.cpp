#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int x;
bool is_prime(ll n){
    for(ll i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    if(n==1) return false;
    return true;
}
int main(void){
    cin>>x;
    while(true){
        if(is_prime(x)){
            cout<<x<<endl;
            return 0;
        }
        x++;
    }

}

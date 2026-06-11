#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <set>
#include <cmath>
#include <array>
#include <bitset>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b+1;i++)
#define Per(i,b,a) for(int i=b;i>=a;i--)

ll binary_method(ll a,ll b){
    if(b==0) return (ll)1;
    ll temp = binary_method(a,b>>1);
    if(b%2){
        return (((temp*temp)%mod)*a)%mod;
    } else{
        return (temp*temp)%mod;
    }
}

int main(){
    string L;
    cin>>L;
    ll N = L.size();
    ll ans = 0;
    ll one_count=0;
    rep(i,N){
        if(L[i]=='0') continue;
        else{
            ans = (ans + binary_method(2,one_count)*binary_method(3,N-1-i))%mod;
            one_count++;
        }
    }
    ans = (ans + binary_method(2,one_count))%mod;
    cout<<ans<<endl;
    return 0;
}
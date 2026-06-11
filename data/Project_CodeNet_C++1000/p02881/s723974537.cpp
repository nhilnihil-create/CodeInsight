
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;


int main(){
    ll n;
    cin >> n;

    ll count=0;
    
    vector<ll> divisor;
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            divisor.push_back(i);
        }
    }
    int len=divisor.size();
    if(divisor.at(len-1) == sqrt(n)){
        count = 2*divisor.at(len-1) - 2;
    }
    else{
        ll div1 = divisor.at(len-1);
        ll div2 = n/(divisor.at(len-1));
        count = div1 + div2 - 2;
    }

    cout << count << endl;
    
}
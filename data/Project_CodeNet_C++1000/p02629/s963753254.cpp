#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const ll mod=26;
const ll m=100;
vector<ll> v;

int main(){
    ll n; cin >> n;
    v.resize(m);
    ll count=0;
    for(; count<m; count++){
        n--;v[count]=n%mod;
        if(n/mod!=0) n/=mod;
        else break;
    }
    for(int i=count; i>=0; i--){ char a=v[i]+97; cout << a;}
    cout <<  "\n";
}
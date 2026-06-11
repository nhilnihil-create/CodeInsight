#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

int main(){
    ll n;
    cin >> n;
    ll ans=0;
    if(n%2==0){
        ll kani=5;
        while(n>=kani){
            ans+=n/(kani*2);
            kani*=5;
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    ll x;
    cin>>x;

    for(ll a=-1000;a<=1000;a++){
        for(ll b=-1000;b<=1000;b++){
            if(a*a*a*a*a-b*b*b*b*b==x){
                cout<<a<<" "<<b<<endl;
                return 0;
            }
        }
    }
}
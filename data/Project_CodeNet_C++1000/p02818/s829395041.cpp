#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1001001001;
const long long MOD = 1000000007;
const double EPS = 1e-10;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll a,b,k;
    cin>>a>>b>>k;
    if(a>=k){
        cout<<a-k<<' '<<b<<endl;
    }else{
        cout<<0<<' '<<max(0LL,b-(k-a))<<endl;
    }
}
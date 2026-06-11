#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    ll a,b,k;
    cin>>a>>b>>k;

    if(a>=k){
        cout<<a-k<<" "<<b<<endl;
    }
    else if(a+b>=k){
        cout<<0<<" "<<b-(k-a)<<endl;
    }
    else cout<<0<<" "<<0<<endl;

}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;
//const ll mod=998244353;

int main(void){
    ll n;
    cin>>n;
    ll d[1000][2];
    for(int i=0;i<n;i++) cin>>d[i][0]>>d[i][1];
    for(int i=0;i<n-2;i++){
        if(d[i][0]==d[i][1]&&d[i+1][0]==d[i+1][1]&&d[i+2][0]==d[i+2][1]){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}
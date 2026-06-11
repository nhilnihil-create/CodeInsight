#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const ll mod=1000000007;
int main(void){
    ll n,k;
    cin>>n>>k;
    if(k>(n-1)*(n-2)/2) cout<<-1<<endl;
    else{
        ll m=n-1+(n-1)*(n-2)/2-k;
        cout<<m<<endl;
        int count=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cout<<i<<" "<<j<<endl;
                count++;
                if(count>=m) break;
            }
            if(count>=m) break;
        }
    }
}
#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for (ll i=0; i < (ll)(n); i++)

ll MOD = 1e9+7;

int main(){
    int s;
    cin>>s;

    vector<ll> a(s+4);
    a[1]=0;
    a[2]=0;
    a[3]=1;
    if(s>=4){
        for(int i=4;i<=s;i++){
            a[i]=(a[i-1]+a[i-3])%MOD;
        }
    }
    cout<<a[s]<<endl;
}
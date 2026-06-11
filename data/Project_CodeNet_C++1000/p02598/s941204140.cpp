#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());

string yes="Yes",no="No";

int main() {
    int n;
    ll k;
    cin>>n>>k;
    vll a(n);
    rep(i,n) cin>>a[i];
    ll ng=-1;
    ll ok=1e9+100;
    while(ok-ng>1){
        ll mid=(ok+ng)/2;
        if(mid==0){
            cout<<1<<endl;
            return 0;
        }
        ll sum=0;
        rep(i,n){
            sum+=(a[i]-1)/mid;
        }
        if(sum>k) ng=mid;
        else ok=mid;
        
       
    }
    cout<<ok<<endl;
  

}

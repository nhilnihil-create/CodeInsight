//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

vector<ll>prime_factorize(ll n){
    vector<ll>res;
    for(ll p = 2;p <= sqrt(n);p++){
        ll cnt=0;
      if (n%p != 0) continue;
      while(n % p == 0){
        n /= p;
        cnt++;
      }
       res.push_back(cnt);
      
    }
    if (n != 1) res.push_back(1);
    return res;
}

int main(){
    ll n; cin>>n;
    vector<ll>data=prime_factorize(n);

    ll ans=0;
    for(int j=0;;j++){
        bool jud=false;
    rep(i,data.size()){
        if(data[i]-(j+1)<0){
            continue;
        }
        else{
            data[i]-=j+1;
            jud=true;
            ans++;
        }
    }
    if(!jud){
        cout<<ans<<endl;
        return 0;
    }
    }

}








































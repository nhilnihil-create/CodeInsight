#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
     map<ll ,ll> cnt;
     ll sum=0;
    rep(i,n){
      cin >> a.at(i);
      cnt[i+1]=0;
    }
    rep(i,n){
      cnt[a.at(i)]++;
    }
    ll m;
    rep(i,n){
      m=cnt[i+1];
      if(m>=2){
      sum+=m*(m-1)/2;
      }
    }
    ll ans;
    rep(i,n){
      m=cnt[a.at(i)];
      if(m>=2)ans=sum-(m-1);
      else ans=sum;
      cout << ans << endl;
    }
}
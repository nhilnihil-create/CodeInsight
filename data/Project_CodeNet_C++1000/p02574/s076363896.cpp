#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
ll mod=1000000007;
ll NMAX = 1000007;

ll gcd(ll a, ll b){
  ll r=a%b;
  while(r>0){
    a = b;
    b = r;
    r = a%b;
  }
  return b;
}

vector<ll> eratosthenes(ll n){
    vector<ll> list(n+1,1);
    for(ll i=0;i<=n;i++){
        list.at(i) = 1;
    }
    ll upper = ceil(sqrt(n));
    for(ll i=2;i<=upper;i++){
        if(list.at(i) == 1){
          	list.at(i) = i;
            ll cnt=2*i;
            while(cnt <= n){
              	if(list.at(cnt) == 1){
	                list.at(cnt)=i;
                }
                cnt += i;
            }
        }
    }

    return(list);
}

int main() {
  ll n;
  vector<ll> a(NMAX);
  const vector<ll> list = eratosthenes(NMAX);
  cin >> n;
  //c[i]:数列aの中でiが出現した回数
  vector<ll> c(NMAX,0);
  rep(i,n){
    cin >> a[i];
    c[a[i]]++;
  }
  
  if(n == 2){
    if(gcd(a[0],a[1]) != 1){
      cout << "not coprime" << endl;
    }else{
      cout << "pairwise coprime" << endl;
    }
    return(0);
  }
  
  bool pairwise=true;
  for(ll i=2;i<NMAX;i++){
    ll cnt=0;
    //iの倍数が何回現れるか
    for(ll j=i;j<NMAX;j+=i){
      cnt += c[j];
    }
    if(cnt > 1) pairwise=false;
  }
  
  if(pairwise){
    cout << "pairwise coprime" << endl;
    return(0);
  }
  
  ll g=gcd(a[0],a[1]);
  //cout << g << endl;
  
  for(ll i=2;i<n;i++){
    g = gcd(a[i],g);
    //cout << g << endl;
  }

  if(g == 1){
    cout << "setwise coprime" << endl;
  }else{
    cout << "not coprime" << endl;
  }
  
  return(0);
}

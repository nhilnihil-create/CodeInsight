#include <bits/stdc++.h>
using namespace std;
 
#define froop1(a,n) for(int i = a;i < n;i++)
#define froop2(a,n) for(int i = a;i > n;i--)
 
#define ll long long
 
#define pq(name,type) priority_queue<type> name
#define vec(name,type,length,value) vector<type> name(length,value)
#define vec2(name,type,length,width,value) vector<vector<type>> name(length,vector<type>(width,value));
 
int main(){
	ll N,K,sum = 0;
  cin >> N >> K;
  vector<ll> a(N,0);
  map<ll,ll> b;
  froop1(0,N){
    cin >> a.at(i);
    if(b.count(a.at(i))){
      b[a.at(i)]++;
    }else{
      b[a.at(i)] = 1;
    }
  }
  ll c = 0,kk = K * (K - 1) / 2;
  kk %= 1000000007LL;
  for(pair<ll,ll> p : b){
    sum += c * kk * p.second;
    sum %= 1000000007LL;
    c += p.second;
  }
  froop1(0,N){
    for(int j = i;j < N;j++){
     if(a.at(i) > a.at(j)) sum += K;
      sum %= 1000000007LL;
    }
  }
  cout << sum << endl;
}
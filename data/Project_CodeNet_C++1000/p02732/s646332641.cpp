#include<iostream>
#include<vector>
#include<string>
typedef long long ll;
#define rep(i,n) for (ll i=0;i<n;i++)
#include <bits/stdc++.h>


using namespace std;


int main(){
	ll N,sum=0;
  cin >> N;
 // vector <pair<int, int>> p;
  map <ll,ll> p;
  vector <ll> tmp(N);
  set <ll> S;
  
  rep(i,N){
    cin>> tmp.at(i); 
    S.insert(tmp.at(i));
  }
  //cout << S.size() << endl;
  //ll n=S.size();
 /* rep(i,n){
    //cout << *begin(S) << endl;
    p[*begin(S)]=0;
    S.erase(*begin(S));
    //cout << p.at(i).first << p.at(i).second << endl;
  }*/
  
  for (auto value : S) {
  p[value]=0;
}
  
  rep(i,N){
    p.at(tmp.at(i))++;
  }
  for (auto q : p) {
    
  auto k = q.first;
  auto v = q.second;
    
    sum+=(v-1)*v/2;
  //cout << k << " => " << v << endl;
}
  //cout << p.size() << endl;
  //vector <ll> a(p.size());
  
  
 /* rep(i,p.size()){
    //cout << p.at(tmp.at(i)) << endl;
    sum+=(p.at(tmp.at(i))-1)*p.at(tmp.at(i))/2;
   // a.at(i)=(p.at(tmp.at(i))-1)*p.at(tmp.at(i))/2;
  }*/
  //cout << sum << endl;
  rep(i,N){
    ll sum2=sum;
    sum2-=(p.at(tmp.at(i))-1)*p.at(tmp.at(i))/2;
    //cout << sum2 << endl;
    p.at(tmp.at(i))--;
    sum2+=(p.at(tmp.at(i))-1)*p.at(tmp.at(i))/2;
    cout << sum2 << endl;
    p.at(tmp.at(i))++;
  }
}
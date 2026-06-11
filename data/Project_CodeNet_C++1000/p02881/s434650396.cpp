#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll N;
  cin >> N;
  vector<pair<ll,ll> >a;
  for(ll i=1;i*i<=N;i++){
    if(N%i==0){
      a.push_back(make_pair(i,N/i));
    }
  }
  ll sum=2*pow(10,12);
  for(ll j=0;j<a.size();j++){
    ll t = a[j].first-1 + a[j].second - 1;
    if(sum>t) sum=t;
  }
  cout << sum << endl;
}

#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
#define repo(i, n) for(int i=1; i<=n; i++)
#define INF 1001001001
#define INFll 100100100100100
// debug用
#define PrintVec(x) for (auto elementPrintVec: x) { cout << elementPrintVec << " "; } cout << endl;

using namespace std;
using ull = unsigned long long;
using ll = long long;
using P = pair<int, int>;
const int mod = 1000000007;

int main(){
  ll x;
  cin >>x;
  /*
  vector<ll> fifth;
  for(ll i=-700; i<=700; i++){
    fifth.push_back(i*i*i*i*i);
  }
  int siz=fifth.size();
  rep(i,siz){
    for(int j=i+1; j<siz; j++){
      if(fifth[j]-fifth[i]==x){
        cout << fifth[j] << " " << fifth[i] << endl;
        return 0;
      }
    }
  }*/
  for(ll i=-700; i<=700; i++){
    for(ll j=i+1; j<=700; j++){
      if(j*j*j*j*j-i*i*i*i*i==x){
        cout << j<< " " << i << endl;
        return 0;
      }
    }
  }
  return 0;
}

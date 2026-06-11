#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(x) cout << fixed << setprecision(x);
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;
 
 
int main(){
  string S;
  cin >> S;
  ll N;
  
 rep(i,S.size()){
if(S.at(i) =='?'){
     S.at(i) = 'D';
   }

 }
  cout << S << endl;
  
}

 
#include <bits/stdc++.h>
#include <limits>
#include <math.h>
#include <cmath>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int> ;
using vi = vector<int> ;
using bb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vll = vector<long long>;
using vvll = vector<vector<long long >>;
#define PI 3.141592653
#define rep(i, n) for(ll i = 0; i < n; i++)

int main(){
  ll n; cin >> n;
  vll a(n);
  vll p(1000001,0);
  rep(i,n){cin >> a[i]; p[a[i]]++;}
  sort(a.begin(),a.end());
	
  ll sum = n;
  rep(i,n){
    if(p[a[i]] > 1){sum--; continue;}
    else if(a[i] <1000){
      rep(j,i){
        if(a[i] % a[j] == 0){sum--; break;}
      }     
    }
    else{
      for(ll j = 2; j <= 1000; j++){
        if(p[j]){
          if(a[i] % j == 0){sum--; break;}
        }
        else if(a[i] % j == 0 && p[a[i]/j]){
          sum--; break;
        }
      }
    }
  }
  if(p[1] == 1){sum = 1;}
  else if(p[1] > 1){sum = 0;}
  
  cout << sum << endl;
}
        
    
        
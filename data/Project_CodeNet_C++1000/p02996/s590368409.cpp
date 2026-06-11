#include<bits/stdc++.h>
using namespace std ; 
#define rep(i,N) for(int i = 0 ; i <(N) ; i++)
typedef long long ll;
typedef pair<int ,int> P ;

int main(){
  int N ; cin >> N ; 
  vector<P> p(N) ; 
  
  rep(i,N) cin >> p[i].second >> p[i].first ; 
  sort(p.begin(),p.end()) ; 
  
  int T = 0 ; 
  rep(i,N){
    T += p.at(i).second ; 
    if( T > p.at(i).first) {
     cout << "No" << endl ;
     return 0 ; 
    }
  }
  
  cout << "Yes" << endl ; 
  
  
  return 0 ;  
}
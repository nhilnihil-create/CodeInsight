#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  long x[n];
  long y[n];
  for(int i=0;i<n;i++){
    cin >> x[i] >> y[i];
  }

  map<pair<long,long>,int>m;
  set<pair<long,long> >s;
  
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i != j){
       long p = x[i]-x[j];
       long q = y[i]-y[j];
       m[make_pair(p,q)]++;
       s.insert(make_pair(p,q));
      }
      
    }
  }
  int maxx = 0;
  for(auto p: s){
    maxx = max(maxx,m[p]);
  }

cout << n-maxx << endl;
  



}

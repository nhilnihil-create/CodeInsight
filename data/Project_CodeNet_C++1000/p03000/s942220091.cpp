#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;

int main() {
 int n,x;
  cin>>n>>x;
  vector<int> l(n);
  rep(i,n){
   cin>>l[i]; 
  }
  /////
  vector<int> hane(1,0);
  int now=0;
  rep(i,n){
    now+=l[i];
   hane.push_back( now);
  }
  int count=0;
  rep(i,n+1){
   if(hane[i]<=x){
    count++; 
   }
    
  }
  cout<<count<<endl;
}
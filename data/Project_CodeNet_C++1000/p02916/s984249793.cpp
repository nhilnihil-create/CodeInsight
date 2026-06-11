#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using namespace std;

int main() {
 int n;
 cin >> n;
 
 vector<int> a(n);
 rep(i,n) {
  cin >>a.at(i);
  }
  
  vector<int> b(n);
  rep(i,n) {
  cin>>b.at(i);
  }
  
  vector<int> c(n);
  c.at(0) = 0;
 for(int i = 1;i<n;i++) {
  cin>>c.at(i);
  }
   
   int ans = 0;
   

     for(int i =0; i<n-1;i++) {
    if(a.at(i)+1 == a.at(i+1)) {
     ans+=c.at(a.at(i));}
     }
     
   for(int i = 0; i<n;i++) {
    ans+=b.at(i);
    }
    
    cout << ans;
    


}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
//using ll = long long;
//using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n){
   cin >> a[i]; 
  }
  rep(i,n){
   if(a[i]%2 != 0) a[i] =0; 
  }
  int counts =0;
  int countsA =0;
  rep(i,n){
   if(a[i]){
     countsA++;
    if(a[i]%3 == 0 || a[i]%5 ==0) counts++; 
   }
  }
  if(counts != countsA) cout << "DENIED" << endl;
  else cout << "APPROVED" << endl;
  
 // cout << counts << endl;
}

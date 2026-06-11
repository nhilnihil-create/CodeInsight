#include <bits/stdc++.h>
using namespace std;

int main(){
  int N ;
  cin >> N;
  int ans =0;
  vector<int> a(25);
  vector<int> b(25);
  vector<int> c(25);
  for(int i=0;i<N;i++) cin >> a[i]; 
  for(int i=0;i<N;i++) cin >> b[i]; 
  for(int i=0;i<N;i++) cin >> c[i]; 
  
  for(int i=0;i<N;i++){
    ans += b[a[i]-1];
    if(a[i]+1==a[i+1]) ans += c[a[i]-1];
  }
  
  
  cout << ans << endl;
}
  
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  int n;
  cin >> n;
  vector<int> a(n+1);
  vector<int> ans(n+1);
  for(int i=1; i < n+1; i++) cin >> a[i];
  for(int i=n; i>=1; i--){
    int check=0;
    int multi = n/i;
    if(multi==1){
      ans[i] = a[i];
    }
    else{
      check=a[i];
      for(int j=1; j<multi;j++){
        if(ans[i*(j+1)]==1) check +=1;
      }
      ans[i] = check%2;
    }
  }
  int m=0;
  rep(i,n+1){
    if(ans[i]==1) m+=1;
  }
  cout << m << endl;
  rep(i,n+1){
    if(ans[i]==1) printf("%d ", i);
  } 
  
}

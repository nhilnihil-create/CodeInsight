#include <bits/stdc++.h>
#define rep(i,n) for (int i = 1; i < (n+1) ;i++)
using namespace std;
using p=pair<int,int>;

int main() {
  long int n;
  cin >> n;
  long int ans=0;
  rep(i,n){
    if(i%3 !=0 && i%5 !=0){
      ans = ans +i;
    }
  }
  
  cout << ans << endl;
  

}

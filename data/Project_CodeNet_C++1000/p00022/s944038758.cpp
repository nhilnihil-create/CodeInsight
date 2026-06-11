#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n;
    while(n!=0){
      vector<int>a(n);
      vector<int>S(n+1);
      S.at(0) = 0;
      for(int i = 0;i < n;i++){
        cin >> a.at(i);
      }
      for(int i = 0;i < n;i++){
         S.at(i+1) = S.at(i) + a.at(i);
      }
      int ans = -99999999990990999;
      for(int k = 0; k < n;k++){
      for(int i = 0; i < n-k  ;i++){
        if(S.at(n-k) - S.at(i) > ans){
          ans = S.at(n-k) - S.at(i);
      }
    }
  }
          cout << ans << endl;
          cin >> n;
        }
}

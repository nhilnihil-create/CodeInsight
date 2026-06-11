#include <bits/stdc++.h>
 #define rep(i,n) for(int i=0;i<n;i++)
 using namespace std;
  int main(){

    vector<char> a(2);
      rep(i,3){
          cin >> a[i];
          if(a[i]=='7'){
              cout << "Yes" << endl;
              break;
          }
          if(i+1==3){
              cout << "No" << endl;
              break;
          }
      }
return 0;
    
  }
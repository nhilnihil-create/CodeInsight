#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main(){
  int X,Y;
  cin>>X>>Y;
  int third = 100000;
  int second = 200000;
  int first = 300000;
  int ans = 0;
  if(X==1 && Y==1){
    ans += 400000;
  }
  if(X==1){
    ans += first;
  }
  else if(X==2){
    ans += second;
  }
  else if(X==3){
    ans += third;
  }

  if(Y==1){
    ans += first;
  }
  else if(Y==2){
    ans += second;
  }
  else if(Y==3){
    ans += third;
  }
 
 cout << ans << endl;
 return 0;
}
#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
 
int main() {
  int N;
  cin>>N;
  int t=N%10;
  if(t==3)cout<<"bon"<<endl;
  else if(t==0 || t==1 || t==6 || t==8)cout<<"pon"<<endl;
  else cout<<"hon"<<endl;
  return 0;
}
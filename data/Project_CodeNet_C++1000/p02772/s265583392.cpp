#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  int flag = 0;
  int sum = 0;

  cin >> n;

  vector<int> a(n);
  vector<int> b(n,0);


  rep(i,n){
    cin >> a.at(i);
    if(a.at(i)%2==0){
      b.at(i) = 1;
      sum++;
    }
  }

  rep(i,n){
    if(b.at(i)==1){
      if(a.at(i)%3==0 || a.at(i)%5==0){
        flag ++ ;
      }
    }
  }

  if(flag == sum)
  cout << "APPROVED";
  else
  cout << "DENIED";
  
}
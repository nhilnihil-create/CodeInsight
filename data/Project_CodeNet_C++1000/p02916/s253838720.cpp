#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <iostream>
#include <ctype.h>
#include <string>
typedef long long ll;
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);

  int sum=0;


  rep(i,n) cin>>a[i];
  rep(i,n) {
      cin>>b[i];
      sum+=b[i];
  }
  rep(i,n) cin>>c[i];

  rep(i,n-1){
      if(a[i]+1==a[i+1]) sum+=c[a[i]-1];
  }

  cout<<sum;

}
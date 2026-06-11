#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i ,n) for(int i = 0 ; i < (n) ; i ++ )
#define all(x) (x).begin(),(x).end()
using ll = long long;
using namespace std;

int main() {
  int k,x;
  cin>>x>>k;
  //////
  int a=k-x+1;
  int b=k+x-1;
  for(int i=a;i<=b;i++){
    cout<<i<<" ";
  }
} 


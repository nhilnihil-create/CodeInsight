#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n;
  cin >> n;
  long a[n];
  rep(i,n)cin >> a[i];
  long all = 0;
  rep(i,n)all ^= a[i];
  rep(i,n){
    long tmp = a[i]^all;
    cout << tmp << " ";
  }
  return 0;
}
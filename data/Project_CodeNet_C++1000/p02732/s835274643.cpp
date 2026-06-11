#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using P =pair<int,int>;
using ll = long long;

int main(){
  int n;
  cin >> n;
  vector<int> a(n),b(n+1);
  rep(i,n) cin >> a[i];
  
  ll sum=0;
  rep(i,n){
    sum+=b[a[i]];
    b[a[i]]++;
  }
  rep(i,n) cout << sum-b[a[i]]+1 << "\n";  
  
  return 0;
}
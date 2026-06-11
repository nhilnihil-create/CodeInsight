#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)	for(int i=0;i<n;i++)
int main(){
  int n;	cin >> n;
  vector<int>	w(n);
  rep(i,n)	cin >> w[i];
  
  int sum=0;
  rep(i,n)	sum+=w[i];
  
  int now=0;
  int ans=sum;
  rep(i,n){
    now+=w[i];
    ans=min(ans,abs(sum-now*2));
  }
   cout << ans; 
}
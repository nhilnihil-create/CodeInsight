#define rep(i,n) for (int i=0;i<n;i++)
#include <vector>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main(){
  
  int H,W,N,ans;
  cin >> H >> W >>N;
  
  ans=N/(max(H,W));
  if(N%(max(H,W))==0)
    cout << ans << endl;
  else
  cout << ans+1 << endl;

 
  
}
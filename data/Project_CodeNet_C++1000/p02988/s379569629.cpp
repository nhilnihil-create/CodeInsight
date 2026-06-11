#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
int main(){
 int n; 
  cin >>n;
  int a[n];
  rep(i, n) cin >> a[i];
  int ans=0;
  for(int i = 1; i < n-1; i++){
   	 if(a[i] < a[i+1] && a[i] > a[i-1])
       ans++;
    else if(a[i] > a[i+1] &&a[i] < a[i-1])
       ans++;
  }
  cout << ans << endl;
}
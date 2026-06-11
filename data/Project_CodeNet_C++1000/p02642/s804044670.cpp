#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define INF 1000000007
using namespace std;

int main(){
  long n;
  cin >> n;
  vector<long> a(n);
  rep(i,n)cin >> a[i];
  sort(a.begin(), a.end());
  long maxa = a[n-1];
  long hyo[maxa+10];
  rep(i,maxa+10)hyo[i] = 0;
  rep(i,n){
    if(i>0 && a[i]==a[i-1]){
      hyo[a[i]] = 1;
      continue;
    }
    int j = 2;
    while(a[i]*j<=maxa){
      hyo[a[i]*j] = 1;
      j++;
    }
  }
  long ans = 0;
  rep(i,n){
    if(hyo[a[i]] == 0)ans++;
  }
  cout << ans << endl;
  return 0;
}
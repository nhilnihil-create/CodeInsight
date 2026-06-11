#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
int main(){
  int n;
  cin >> n;
  
  int x[n],l[n];
  rep(i,n) cin >> x[i] >> l[i];
  
  P num[n];
  rep(i,n){
    num[i].first = x[i] + l[i];
    num[i].second = i;
  }
  
  sort(num, num + n);
  
  //rep(i,n) cout << num[i].first << ":" << num[i].second << endl;
  //cout << endl;
  
  int ans = 1, ex = num[0].second;
  rep(i,n){
    if(i == 0) continue;
    int j = num[i].second;
    if(x[ex]+l[ex] > x[j]-l[j]) continue;
    ans++;
    ex = j;
  }
  
  cout << ans << endl;
  
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;	cin >> n;
  vector<int>	a(n+1);
  for(int i=1;i<=n;i++)	cin >> a[i];
  
  int total=0;
  vector<int>	ans(n+1);
  for(int i=n/2+1;i<=n;i++){
    ans[i]=a[i];
    if(ans[i]==1)	total++;
  }
  
  for(int i=n/2;i>=1;i--){
    int cnt=2;
    int sum=0;
    while(i*cnt<=n){
      sum+=ans[i*cnt];
      cnt++;
    }
    if(sum%2==a[i])	a[i]=0;
    else{
      ans[i]=1;
      total++;
    }
  }
  cout << total << endl;
  for(int i=1;i<=n;i++){
    if(ans[i]==0)	continue;
    cout << i << endl;
  }
}
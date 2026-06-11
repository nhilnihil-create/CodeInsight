#include <bits/stdc++.h>
using namespace std;

int main(){
  
  long long n;
  cin >> n;
  vector<long long> a(n);
  for(int i=0; i<n; i++){
    cin >> a[i];
  }
  long long ans=0;
  long long cnt;
  for(int i=1; i<n; i++){
    if(a[i]<=a[i-1]){
      cnt++;
    }
    else{
      cnt=0;
    }
    ans=max(ans,cnt);
  }
  
  cout << ans << endl;
}
    


#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[10000];

  for(int i=0; i<n; i++) cin>>a[i];

  int mn = a[0], mx =a[0];

  long long sum = 0;

  for (int i=0; i<n; i++){
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
    sum += a[i];
  }

  cout<<mn<<" "<<mx<<" "<<sum<<endl;
  

  return 0;
  
}
	

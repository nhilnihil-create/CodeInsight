#include <bits/stdc++.h>
using namespace std;

int cut_times(int* logs, int n, int min_length) {
  int ans = 0;
  for(int i=0; i<n; i++) {
    ans += (logs[i]-1)/min_length;
  }

  return ans;
}

int main() {
  int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0; i<n; i++) cin>>a[i];

  // sort(a, a+n, greater<int>());

  int left = 1;
  int right = 1000000000;

  while(left<right) {
    int mid = (left+right)/2;
    if(cut_times(a,n,mid) > k) {
      left = mid+1;
    }
    else if(cut_times(a,n,mid) <= k) {
      right = mid;
    }
  }

  cout<<left<<endl;

  return 0;
}
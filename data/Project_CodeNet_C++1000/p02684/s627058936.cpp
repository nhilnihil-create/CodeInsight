#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int64_t k;
  cin>>n>>k;
  int a[n];
  for(int i=0; i<n; i++) cin>>a[i];

  int seen[n];
  for(int i=0; i<n; i++) seen[i] = -1;

  seen[0] = 0;
  int posi = 0;
  int count = 0;
  while(true) {
    posi = a[posi]-1;
    count++;

    if(count==k) {
      cout<<posi+1<<endl;
      return 0;
    }

    if(seen[posi]!=-1) {
      break;
    }

    seen[posi] = count;
  }

  int roop = count - seen[posi];
  int initial = seen[posi];

  int rest = (k-initial)%roop;

  while(rest>0) {
    posi = a[posi]-1;
    rest--;
  }

  cout<<posi+1<<endl;


  return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int,int> P;
typedef long long ll;

int a[100005];
P A[100005];

int main() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> a[i];

  sort(a,a+n);

  if(a[n-1] < 0) {
    for(int i = 0; i < n - 1; i++) {
      A[i] = P(a[n-1],a[i]);
      a[n-1] = a[n-1] - a[i];
    }
  }
  else if(a[0] < 0 && a[n-1] >= 0) {
    int i = n - 2;
    int k = 0;
    while(i >= 0 && a[i] >= 0) {
      A[k++] = P(a[0],a[i]);
      a[0] = a[0] - a[i];
      i--;
    }

    for(int j = 0; j <= i; j++) {
      A[k++] = P(a[n-1],a[j]);
      a[n-1] = a[n-1] - a[j];
    }
  }
  else {
    for(int i = 0; i < n - 2; i++) {
      A[i] = P(a[i],a[i+1]);
      a[i+1] = a[i] - a[i+1];
    }
    A[n-2] = P(a[n-1],a[n-2]);
    a[n-1] = a[n-1] - a[n-2];
  }
  cout << a[n-1] << endl;

  for(int i = 0; i < n - 1; i++) {
    cout << A[i].first <<" "<< A[i].second << endl;
  }
}
  
  

  

  


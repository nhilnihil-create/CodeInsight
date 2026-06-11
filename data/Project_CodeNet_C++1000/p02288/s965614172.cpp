#include <iostream>
using namespace std;

#define L(X) ((X)*2)
#define R(X) ((X)*2+1)
#define P(X) ((X)/2)

void maxHeapify(int *h, int sz, int i){
  int t,mx = i;
//  cout << "MH: " << i << " ";
  if (L(i)<=sz && h[mx]<h[L(i)]) mx = L(i);
  if (R(i)<=sz && h[mx]<h[R(i)]) mx = R(i);
//  cout << mx << endl;
  if (mx!=i){
    t = h[i]; h[i] = h[mx]; h[mx] = t;
    if (L(mx)<=sz) maxHeapify(h,sz,mx);
  }
}

void build(int *h, int sz){
  for (int i=P(sz); i>=1; i--) maxHeapify(h,sz,i);
}

int main(void){
  int h[500010];
  int n;
  
  cin >> n;
  for (int i=0; i<n; i++){
    cin >> h[i+1];
  }
  build(h,n);
  for (int i=1; i<=n; i++){
    cout << " " << h[i];
  }
  cout << endl;
  return 0;
}

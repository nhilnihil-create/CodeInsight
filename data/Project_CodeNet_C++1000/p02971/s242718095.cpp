#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
 int n; cin >> n;
 vector<int> a(n),b(n);
 int amax=-1;
  rep(i,n){
   cin >> a[i];
   b[i]=a[i];
    if(a[i]>amax){
     amax=a[i];
    }
  }
 sort(b.begin(),b.end());

  rep(i,n){
    if(a[i]!=amax)cout << amax << endl;
    else cout << b[n-2] << endl;
  }
}

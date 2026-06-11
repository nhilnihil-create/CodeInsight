#include <bits/stdc++.h>
using namespace std;
#define rep(i,c) for(int i=0;i<c;++i)
#define PI 3.14159265358979323846264338327950L
typedef unsigned long long uint64;
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  rep(i,n){
    cin >> a[i];
  }
  for(int i= 0;i<n;i++){
    if((a[i]%2==0)&&(a[i]%3!=0&&a[i]%5!=0)){
      cout << "DENIED" << endl;
      return 0;
    }
  }
  cout << "APPROVED" << endl;
}

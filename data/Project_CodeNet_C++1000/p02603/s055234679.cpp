#include <iostream>
using namespace std;

int main (){
  long long n,m=1000,s=0;
  
  cin >> n;
  int a[n];
  for (int i=0;i<n;i++) cin >> a[i];
  for (int i=0;i<n-1;i++) {
    if (a[i]<a[i+1]) {
      long long t=m/a[i];
      s+=t;
      m-=t*a[i];
      //cout << "buy" << " ";
    }
    if (a[i]>a[i+1]) {
      m+=s*a[i];
      s=0;
      //cout << "sell" << " ";
    }
    //cout << s << " " << m << endl;
  }
  m+=s*a[n-1];
  s=0;
  cout << m << endl;
}

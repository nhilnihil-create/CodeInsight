#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;
  vector<int> a(n);
  for(long long i=0;i<n;i++){
    cin >> a[i];
  }
  
  long long m=1000, b=0;
  for(int i=0;i<n-1;i++){
    
    if(a[i] > a.at(i+1)){
      m += a.at(i) * b;
      b=0;
    }
    else{
      b += m / a.at(i);
      m %= a[i];
    }
      
  }
   m += b*a[n-1];
  cout << m << endl;
}

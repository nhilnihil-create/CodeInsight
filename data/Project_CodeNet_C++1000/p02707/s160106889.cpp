#include <bits/stdc++.h>
using namespace std;

long long a[2000000];
int main() {
  long long n;
  cin >> n;
  for(int i=1;i<n;i++){
    int s;
    cin >> s;
    a[s-1]++;
    
  }
  for(int i=0;i<n;i++){
    cout << a[i] << endl;
  }
    
}
  

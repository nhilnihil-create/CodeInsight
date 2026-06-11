#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n;
  while(cin >> n, n){
    vector<double> s(n);
    for(int i=0; i<n; i++)
      cin >> s[i];

    double sum = accumulate(s.begin(), s.end(), 0);
    double sigma2 = 0;
    for(int i=0; i<n; i++)
      sigma2 += (sum - n*s[i]) * (sum - n*s[i]);
    sigma2 /= n*n*n;
    
    printf("%0.8f\n", sqrt(sigma2));
  }

  return 0;
}